#include <iostream>
#include <string>
#include <regex>

/*
 *  To build:
 *
 *  > g++ -std=c++11 example.cpp 
 *
 */

int main () {
  auto raw = std::string("vertex -1.624555 -4.999952 -8.506543");
  std::smatch match_itr;
  std::regex pattern("[0-9-.]+");
  while(std::regex_search(raw, match_itr, pattern)) {
    std::cout << match_itr[0] << "\n";
    raw = match_itr.suffix().str();
  }
  return 0;
}
