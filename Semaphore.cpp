#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

counting_semaphore<1> sem(1); // Binary semaphore

void task(int id)
{
    sem.acquire(); // wait

    cout << "Thread " << id << " entered critical section\n";

    this_thread::sleep_for(chrono::seconds(1));

    cout << "Thread " << id << " leaving critical section\n";

    sem.release(); // signal
}

int main()
{
    thread t1(task, 1);
    thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}
