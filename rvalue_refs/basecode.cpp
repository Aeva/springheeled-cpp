#include <iostream>
#include <string>

std::string get_name() {
  return "Aeva";
}


std::string get_name2() {
  return std::string("Aeva");
}


std::string get_name3() {
  auto name = std::string("Aeva");
  return name;
}


template<typename T> T detect(T& name) {
  std::cout << "---> L\n\n";
  return name;
}


template<typename T> T detect(T&& name) {
  std::cout << "---> R\n\n";
  return name;
}


int main () {
  std::cout << "Does get_name() return an l-value or an r-value?\n";
  auto tmp = detect(get_name());

  std::cout << "Does get_name2() return an l-value or an r-value?\n";
  tmp = detect(get_name2());

  std::cout << "Does get_name3() return an l-value or an r-value?\n";
  tmp = detect(get_name3());

  std::cout << "Is the var 'tmp' an l-value or an r-value?\n";
  tmp = detect(tmp);
  
  std::cout << "What would detect(detect(tmp)) do?\n";
  tmp = detect(detect(tmp));

  std::cout << "What would detect(23) do?\n";
  tmp = detect(23);

  
  std::string copied = get_name();
  std::cout << "   copied: " << copied << " " << &copied << "\n";

  std::string&& moved = get_name();
  std::cout << "  moved 1: " << moved << " " << &moved << "\n";

  moved = get_name();
  std::cout << "  moved 2: " << moved << " " << &moved << "\n";

  moved = std::move(moved);
  std::cout << "std::move: " << moved << " " << &moved << "\n";
  
  return 0;
}
