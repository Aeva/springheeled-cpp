#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <mutex>
#include <array>
#include <deque>

/*
 *  To build:
 *
 *  > g++ -std=c++11 -pthread locking_rewrite.cpp 
 *
 */

std::mutex mtx;
const uint width = 79;
const uint lines = width/2;
auto buffer = std::array<char[width+1], lines>();


void clear () {
  for (int line=0; line<lines; line+=1) {
    for (int i=0; i<width; i+=1) {
      buffer[line][i] = ' ';
    }
  }
};

void print () {
  for (int line=0; line<lines; line+=1) {
    std::cout << "|" << buffer[line] << "|\n";
  }
};


void draw_rect(char stamp, uint x, uint y, uint w, uint h) {
  mtx.lock();
  for (uint row=y; row<y+h; row+=1) {
    if (row >= lines) {
      break;
    }
    for (uint col=x; col<x+w; col+=1) {
      if (col >= width) {
        break;
      }
      buffer[row][col] = stamp;
    }
  }
  mtx.unlock();
};


void draw_sqr(char stamp, uint x, uint y, uint w) {
  uint h = w * 0.55;
  draw_rect(stamp, x, y, w, h);
};


std::deque<std::future<void> > futures;
template<typename T> void async(T call) {
  futures.push_back(std::async(std::launch::async, call));
}


int main () {
  clear();

  const char* gradient = "#o8%#";

  for (int i=0; i<5; i+=1) {
    char brush = gradient[i];
    uint x = (i) * 2 + 1;
    uint y = (i) * 3 + 1;
    uint w = (i+1) * 10;
    async(std::bind(draw_sqr, brush, x, y, w));
  }

  for (auto& future : futures) {
    future.wait();
  }

  print();
};
