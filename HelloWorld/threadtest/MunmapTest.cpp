//
// Created by lvwei on 2023/12/31.
//

#include "MunmapTest.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sys/wait.h>
#include "ConstDefine.h"


MunmapTest::MunmapTest() {


}

MunmapTest::~MunmapTest() {

}

void MunmapTest::test() {
    LOG_INFO
    int fd = open("mytxt.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("Failed to open file");
        return;
    }

    ftruncate(fd, sizeof(int));  // 设置文件大小为一个 int 类型的大小

    int *shared_data = (int *) mmap(NULL, 1024 * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);  // 可以关闭文件描述符

    int pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // 子进程
        sleep(2);  // 等待父进程写入数据

        std::cout << "Child process: shared_data =" << std::to_string(*shared_data) << std::flush << std::endl;
        std::cout << "Child process: shared_data2 =" << std::to_string(*(shared_data + 1)) << std::flush << std::endl;
    } else if (pid > 0) {
        // 父进程
        *shared_data = 1234;
        *(shared_data + 1) = 5678;
        std::cout << "Parent process: wrote data to shared_data =" << std::to_string(*shared_data) << std::endl;
        pid_t resPid = wait(nullptr);
        std::cout << "Parent process: " << resPid << std::endl;
    } else {
        perror("Fork failed");
    }

    munmap(shared_data, sizeof(int));
}
