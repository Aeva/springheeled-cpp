#include <iostream>

/*
 * Note that you need C++11 to use type inference.  To compile againts
 * C++11, use the following command:
 *
 *  > g++ -std=c++11 type_inference.cpp 
 *
 */

int main() {
  auto some_int = 10;
  for (int i=0; i<some_int; i+=1) {
    std::cout << i << ": this space intentionally left blank\n";
  }
  return 0;
}
