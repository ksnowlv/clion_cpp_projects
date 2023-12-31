#include "FutureTest.h"
#include <chrono>
#include <iostream>
#include <future>
#include <string>
#include <thread>
#include <unistd.h>
#include <utility>

FutureTest::FutureTest()
{

}

FutureTest::~FutureTest()
{

}

void FutureTest::Test() {

    TestAsync();
    TestPackagedTask();
    TestPromise();
}

int FutureTest::ProcessBigDataTest(const int number1, const int number2) {
    cout << "---" <<__func__<<" threadID:" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(5));
    return (number1 + number2);
}

void FutureTest::ShowMyInfomation(const string& s) {
    cout<<"-----"<<__func__<<"message:"<<s<<endl;
}

void FutureTest::TestAsync() {
    cout<<"-----"<<__func__<<"---"<<endl;
    future<int> result = std::async(launch::async,FutureTest::ProcessBigDataTest,1,2);
    ShowMyInfomation("1+2:");
    
    future_status status;
    while (true) {
          status = result.wait_for(chrono::seconds(1));
        
          if (status == future_status::deferred) {
            cout<<"数据正在处理中"<<"thread_id:"<<this_thread::get_id()<<endl;
            result.wait();
          } else if (status == future_status::ready){
            cout<<"数据处理完成"<<"thread_id:"<<this_thread::get_id()<<endl;
            break;
          } else if ( status == future_status::timeout) {
            cout<<"数据处理超时，继续处理中"<<"thread_id:"<<this_thread::get_id()<<endl;
          }
    } 

    cout<<result.get()<<endl;
}

//通过packaged_task包装后，可以通过thread启动或者仿函数形式启动，
//其执行结果返回值或所抛异常被存储于能通过 std::future 对象访问的共享状态中。
void FutureTest::TestPackagedTask() {

    cout<<"-----"<<__func__<<"---"<<endl;
    packaged_task<int (int,int)> task(FutureTest::ProcessBigDataTest);
    this_thread::sleep_for(::chrono::seconds(2));
    ShowMyInfomation("");
    future<int> result = task.get_future();
    task(1,2);
    cout<<"task result:"<< result.get()<<endl;
     //重置共享状态
    task.reset();
    result = task.get_future();
    //通过线程启动任务，异步启动
    thread td(std::move(task),2,3);

    cout << "task result:" << result.get() <<endl;

    td.join();

    //
    packaged_task<int (int, int)> newTask([](int a, int b) {
        return a + b;
    });

    result = newTask.get_future();
    newTask(4,5);
    cout << "newTask result:" << result.get() <<endl;
 }

void FutureTest::TestPromise() {
    cout<<"-----"<<__func__<<"---"<<endl;
    promise<string> promise;
    future<string> result = promise.get_future();
    thread t1([] (::promise<string>& p) {
        this_thread::sleep_for(::chrono::seconds(2));
        p.set_value("set my value:ksnow!!!");
    }, ref(promise));

    t1.join();

    cout<<result.get()<<endl;
}