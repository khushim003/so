/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Write a Program to Implementation of Classical problems using Threads and
//Semaphore.
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <semaphore.h>

#define BUFFER_SIZE 5

std::mutex mtx;
std::queue<int> buffer;
sem_t empty, full;

void producer() {
    for (int i = 0; i < 10; i++) {
        sem_wait(&empty);
        mtx.lock();
        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;
        mtx.unlock();
        sem_post(&full);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);
        mtx.lock();
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << item << std::endl;
        mtx.unlock();
        sem_post(&empty);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
