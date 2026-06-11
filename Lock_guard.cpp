#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void printMessage()
{
    lock_guard<mutex> lock(mtx);

    cout << "Thread is running" << endl;
}

int main()
{
    thread t1(printMessage);
    thread t2(printMessage);

    t1.join();
    t2.join();

    return 0;
}
