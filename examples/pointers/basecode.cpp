#include <iostream>

int main() {
  int a = 10;
  int& b = a;
  b += 10;
  std::cout << " 'a' is " << a << "\n";
  std::cout << " 'b' is " << b << "\n";
  std::cout << "'&a' is " << &a << "\n";
  std::cout << "'&b' is " << &b << "\n";

  int c = 10;
  int*d = &c;
  std::cout << " 'c' is " << c << "\n";
  std::cout << "'&c' is " << &c << "\n";
  std::cout << " 'd' is " << d << "\n";
  std::cout << "'*d' is " << *d << "\n";
  std::cout << "'&d' is " << &d << "\n";

  return 0;
}
