#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void printMessage()
{
    mtx.lock();

    cout << "Thread is running" << endl;

    mtx.unlock();
}

int main()
{
    thread t1(printMessage);
    thread t2(printMessage);

    t1.join();
    t2.join();

    return 0;
}
