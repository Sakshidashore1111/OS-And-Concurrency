#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1;
mutex m2;

void task1() {
    m1.lock();
    cout << "Task 1 locked m1" << endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Task 1 waiting for m2" << endl;
    m2.lock();

    cout << "Task 1 locked m2" << endl;

    m2.unlock();
    m1.unlock();
}

void task2() {
    m2.lock();
    cout << "Task 2 locked m2" << endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Task 2 waiting for m1" << endl;
    m1.lock();

    cout << "Task 2 locked m1" << endl;

    m1.unlock();
    m2.unlock();
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
