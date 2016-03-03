#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <mutex>

/*
 *  To build:
 *
 *  > g++ -std=c++11 -pthread basecode.cpp 
 *
 */


std::mutex mtx;


void worker (const char* statement) {
  for (int i=0; i<100; i+=1) {
    mtx.lock();
    std::cout << statement << "\n";
    mtx.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}



int main() {
  std::future<void> future_a =
    std::async(std::launch::async, std::bind(worker, "meep"));
  
  std::future<void> future_b =
    std::async(std::launch::async, std::bind(worker, "raar"));

  future_a.wait();
  future_b.wait();

  return 0;
}
