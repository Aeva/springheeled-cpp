#include <iostream>


/*
 *  To build:
 *
 *  > g++ -std=c++11 casting.cpp 
 *
 */


int print_calls = 0;
template<typename T> void print (T value, const char* label = nullptr) {
  print_calls += 1;
  if (label == nullptr) {
    std::cout << "call " << print_calls;
  }
  else {
    std::cout << label;
  }
  std::cout << ": " << value << "\n";
}


int main() {
  print(10);
  print(20.3);
  print("foo");
  print(2, "1+1");
  print("hello world", "some str");
  return 0;
}
