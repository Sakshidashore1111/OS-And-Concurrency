#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

counting_semaphore<3> sem(3);

void worker(int id)
{
    sem.acquire();   // decrease count

    cout << "Worker " << id << " entered\n";

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Worker " << id << " leaving\n";

    sem.release();   // increase count
}

int main()
{
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);
    thread t4(worker, 4);
    thread t5(worker, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
