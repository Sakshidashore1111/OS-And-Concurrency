#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex forks[5];

void philosopher(int id)
{
    forks[id].lock();
    forks[(id + 1) % 5].lock();

    cout << "Philosopher " << id << " is eating" << endl;

    forks[id].unlock();
    forks[(id + 1) % 5].unlock();
}

int main()
{
    thread p1(philosopher, 0);
    thread p2(philosopher, 1);
    thread p3(philosopher, 2);
    thread p4(philosopher, 3);
    thread p5(philosopher, 4);

    p1.join();
    p2.join();
    p3.join();
    p4.join();
    p5.join();

    return 0;
}
