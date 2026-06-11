#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void slowWork() {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"slowWork\n";
}

void quickWork() {
    cout<<"quickWork\n";
}

int main() {

    thread t1(slowWork);
    cout<<"wait for t1..."<<endl;
    t1.join();
    cout<<"t1 finish.main continues"<<endl;

    thread t2(quickWork);
    t2.detach();
    cout<<"t2 detach and main continues"<<endl;

    this_thread::sleep_for(chrono::milliseconds(100));
    return 0;
}

//
// Created by hp on 12-06-2026.
//
