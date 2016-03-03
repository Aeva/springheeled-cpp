#include <iostream>
#include <typeinfo>

/*
 *  To build:
 *
 *  > g++ -std=c++11 basecode.cpp 
 *
 */

int main() {
  auto floob = "This is a test!";
  decltype(floob) thingy = "hello world";
  std::cout << typeid(thingy).name() << " : \"" << thingy << "\"\n";
  return 0;
}
