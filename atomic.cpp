#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);

// 线程函数，对全局计数器进行递增操作
void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counter.fetch_add(1); // 原子递增操作
    }
}

int main() {
    const int numThreads = 5;
    std::thread threads[numThreads];

    // 创建多个线程，每个线程对计数器进行递增操作
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(incrementCounter);
    }

    // 等待所有线程完成
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // 输出计数器的最终值
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}

