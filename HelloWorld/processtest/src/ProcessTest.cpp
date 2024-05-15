#include "ProcessTest.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <type_traits>
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/msg.h>

using namespace std;

auto g_value = 11;

ProcessTest::ProcessTest() {

}

ProcessTest::~ProcessTest() {

}


void ProcessTest::test() {
    // processCreate();
    // signalTest();
    // alarmTest();
    sharedMemoryTest();
    //MessageQueueTest();
}

/**
 Linux系统下可以通过调用 fork() 来创建一个新的进程。调用进程为父进程 (parent process) ，而诞生的新进程为子进程 (child process)。

fork() 比较特别，因为它会返回两次，也就是说会有两个返回值。
我们可以通过这两个返回值来区分父、子进程。在父进程中，fock() 将会返回子进程的 process ID，
而在子进程中成功返回0，失败则返回-1 (失败原因可参考手册)。子进程可以调用 getpid() 获取进程ID。

使用fork创建进程，子进程终止时，它与父进程之间的关联还会保持，直到父进程也正常终止或父进程调用wait才结束。如果父进程异常终止，子进程会自动
将PID为1的进程（init）作为自己的父进程，由init进程接管。
 *
 */
void ProcessTest::processCreate() {

    auto localValue = 10;

    pid_t childPid = fork();

    switch (childPid) {
        case -1:
            std::cout << "failed to fork!!!" << std::endl;
            exit(-1);

        case 0://表示创建子进程成功
            cout << "child process id:" << getpid() << endl;
            cout << "global value:" << (++g_value) << endl;
            cout << "local value:" << ++localValue << endl;
            cout << "----------" << endl;
            sleep(5);
            cout << "child process exit" << endl;
            exit(0);
            break;

        default:
            cout << "parent process id:" << getpid() << endl;
            cout << "global value:" << (++g_value) << endl;
            cout << "local value:" << ++localValue << endl;
            cout << "----------" << endl;
            int stat = -1;
            pid_t pid = wait(&stat);
            cout << "child has finished:pid=" << pid << endl;
            //WIFEXITED(stat)若此值为非0 表明进程正常结束；若该宏为真，此时可通过WEXITSTATUS(status)获取进程退出状态(exit时参数)
            if (WIFEXITED(stat)) {
                cout << " child exited with code:" << WEXITSTATUS(stat) << endl;
            } else if (WIFSIGNALED(stat)) {// WIFSIGNALED(status)为非0 表明进程异常终止,此时可通过WTERMSIG(status)获取使得进程退出的信号编号
                cout << "使得进程退出的信号编号:" << WIFSIGNALED(stat) << endl;
            } else {
                cout << " child terminated abnormally!" << endl;
            }
            while (1) {
                sleep(10);
                cout << "parent process continue" << endl;
                break;
            }
            break;
    }
}

void ProcessTest::signalTest() {

    cout << "--------signal test-----" << endl;
    signal(SIGINT, ProcessTest::ouch);

    int count = 0;
    while (++count > 5) {
        cout << "Hello world!!!" << endl;
        sleep(2);
    }
}

void ProcessTest::ouch(const int sig) {
    cout << "O! i got signal:" << sig << endl;
}

// alarm
int ProcessTest::s_AlarmFired = 0;

void ProcessTest::alarmTest() {
    cout << "---alarm application start---" << endl;
    pid_t pid = fork();
    pid_t childPid;
    if (pid == -1) {
        cout << "fork fail!!!" << endl;
    } else if (pid == 0) {
        sleep(5);
        childPid = getpid();
        pid_t ppid = getppid();
        cout << "child process id:" << childPid << "----parent process id:" << ppid << endl;
        int res = kill(ppid, SIGALRM);
    }

    //cout<<"alarm_fired:"<<alarm_fired<<",pid:"<<getpid()<<endl;

    signal(SIGALRM, ProcessTest::alarmCallBack);
    pause();
    if (ProcessTest::s_AlarmFired > 0) {
        cout << "alarm Call Back" << endl;
    }
}

void ProcessTest::alarmCallBack(const int sig) {
    ProcessTest::s_AlarmFired = 1;
}

void ProcessTest::sharedMemoryTest() {
    cout << __func__ << endl;
    const int sharedMemorySize = 1024;
    const int keyId = 256;
    const char *sharedText = "Hello world!";
    pid_t pid = fork();

    if (pid == -1) {
        cout << "fork fail!!!" << endl;
        return;
    } else if (pid == 0) {
        //获取唯一的key值
        key_t key = ftok("/", keyId);
        //创建或打开一块共享内存
        int shmId = shmget(key, sharedMemorySize, IPC_CREAT | 0666);
        if (shmId == -1) {
            cout << "create shared memory fail!" << endl;
            return;
        }
        cout << "child process pid:" << getpid()
             << ",parent process pid:" << getppid()
             << ",key=" << key
             << ",shmid:" << shmId << endl;
        //将一块共享内存映射到调用进程的数据段中
        char *buf = (char *) shmat(shmId, nullptr, 0);
        memcpy(buf, sharedText, strlen(sharedText));
        cout << "write buf:" << buf << endl;
        //将共享内存和当前进程分离(仅仅是断开联系并不删除共享内存)
        shmdt(buf);
    } else if (pid > 0) {
        cout << "----pid:" << pid << endl;
        key_t key = ftok("/", keyId);
        int shmId = shmget(key, sharedMemorySize, IPC_CREAT | 0666);
        if (shmId == -1) {
            cout << "create shared memory fail!" << endl;
            return;
        }
        cout << "parent process pid:" << getpid() << ",key=" << key << ",shmid:" << shmId << endl;
        const char *buf = (char *) shmat(shmId, nullptr, 0);
        cout << "read buf:" << buf << endl;
        shmdt(buf);
        pid_t resPid = wait(nullptr);
        cout << resPid << endl;
    }
}

struct MsgBuf {
    long m_Type;
    char m_data[256];
};

void ProcessTest::messageQueueTest() {
    sleep(2);
    cout << "----" << __func__ << endl;
    const int sharedMemorySize = 1024;
    const int keyId = 256;
    const char *sharedText = "Hello world!";
    const int msgType = 1;

    pid_t pid = fork();

    if (pid == -1) {
        cout << "fork fail!!!" << endl;
        return;
    } else if (pid == 0) {
        //获取唯一的key值
        key_t key = ftok("/", keyId);
        //创建或打开消息队列
        int msgId = msgget(key, IPC_CREAT | 0666);
        if (msgId == -1) {
            cout << "create msg fail!" << endl;
            return;
        }
        cout << "child process pid:" << getpid()
             << ",parent process pid:" << getppid()
             << ",key=" << key
             << ",msgId:" << msgId << endl;
        //将一块共享内存映射到调用进程的数据段中

        int count = 0;
        struct MsgBuf msgBuf;
        while (true) {
            msgBuf.m_Type = msgType;

            memcpy(msgBuf.m_data, sharedText, strlen(sharedText));

            int res = msgsnd(msgId, &msgBuf, sizeof(msgBuf.m_data), IPC_NOWAIT);

            if (res == -1) {
                cout << "send message fail!" << endl;
                return;
            }
            sleep(2);

            if (++count > 10) {
                break;
            }
        }


        //将共享内存和当前进程分离(仅仅是断开联系并不删除共享内存)

    } else if (pid > 0) {

        key_t key = ftok("/", keyId);
        int msgId = msgget(key, IPC_CREAT | 0666);
        if (msgId == -1) {
            cout << "create msg fail!" << endl;
            return;
        }

        cout << "----pid:" << pid << ",msgid:" << msgId << endl;

        while (true) {
            struct MsgBuf msgBuf;
            int res = msgrcv(msgId, &msgBuf, sizeof(msgBuf.m_data), msgType, IPC_NOWAIT);
            if (res == -1) {
                cout << "rev message fail!" << endl;
                sleep(1);
            } else {
                cout << "rev msg type:" << msgBuf.m_Type << " rev msg:" << msgBuf.m_data << endl;
            }
        }
        pid_t resPid = wait(nullptr);
        cout << "##########" << resPid << endl;
    }
}
