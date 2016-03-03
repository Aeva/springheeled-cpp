#include <iostream>


typedef void (*type_a)(int);
typedef void (*type_b)();


void print (int a) {
  std::cout << a << "\n";
}


void print () {
  std::cout << "flaming garbage\n";
}


int main() {
  type_a foo = print;
  type_b bar = print;

  foo(10);
  bar();
  
  return 0;
}
