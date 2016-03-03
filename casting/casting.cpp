#include <iostream>

int main() {
  double some_num = 1.4;
  int a = (int) some_num;
  int b = static_cast<int> (some_num);
  std::cout << "c-style cast: " << a << "\n";
  std::cout << " static cast: " << b << "\n";
  return 0;
}
