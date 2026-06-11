#include<iostream>
#include<thread>
using namespace std;

//function that threads will execute

void sakshi()
{
    cout<<"hello thread 1 \n";
}

void suyash() {
    cout<<"hello thread 2 \n"
;}

int main() {

    thread t2(suyash);
    thread t3([]() {
        cout<<"t3 works\n";
    });
    thread t1(sakshi);


    t1.join();
    t3.join();
    t2.join();
    cout<<"all threads finished\n";
    return 0;
}

/*to fix order, write like this or use mutex or condition variable or semaphore or locks
thread t1(sakshi);
t1.join();

thread t2(suyash);
t2.join();*///
// Created by hp on 12-06-2026.
//
