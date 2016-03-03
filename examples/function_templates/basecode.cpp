#include <iostream>

template<typename T> void foo(T param) {
  std::cout << param << "\n";
}

int main() {

  foo(20);
  foo(20.3);
  foo("hello world!");

  return 0;
}
