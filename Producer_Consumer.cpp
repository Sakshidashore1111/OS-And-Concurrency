#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

queue<int> buffer;
const int MAX_SIZE = 5;

mutex mtx;
condition_variable cv;

void producer() {
    for (int i = 1; i <= 10; i++) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return buffer.size() < MAX_SIZE;
        });

        buffer.push(i);
        cout << "Produced: " << i << endl;

        cv.notify_one();
    }
}

void consumer() {
    for (int i = 1; i <= 10; i++) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return !buffer.empty();
        });

        int item = buffer.front();
        buffer.pop();

        cout << "Consumed: " << item << endl;

        cv.notify_one();
    }
}

int main() {

    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    return 0;
}
