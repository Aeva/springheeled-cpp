#include <iostream>
#include <memory>
#include <string>


/*
 *  To build:
 *
 *  > g++ -std=c++11 unique_ptr.cpp
 *
 */


using std::unique_ptr;


class Resource {
public:
  Resource() {
    std::cout << "misc resource initialized\n";
  }
  ~Resource() {
    std::cout << "misc resource deleted\n";
  }
};


class Thingy {
public:
  Thingy() : res(new Resource) {
    std::cout << "thingy initialized\n";
  }
  ~Thingy() {
    std::cout << "thingy deleted\n";
  }
private:
  unique_ptr<Resource> res;
};


int main() {
  // --- will refuse to compile ---
  // auto foo = unique_ptr<const char*>("Hello world!");
  
  auto foo = unique_ptr<const char*>(new (const char*)("Hello world!"));
  auto bar = unique_ptr<int>(new int(10));
  // std::cout << foo << "\n"; // <----- will refuse to compile
  // std::cout << bar << "\n"; // <----- will refuse to compile
  std::cout << *foo << "\n";
  std::cout << *bar << "\n";

  auto baz = unique_ptr<std::string>(new std::string("Is this thing on?"));
  std::cout << *baz << "\n";

  baz.reset();
  // std::cout << *baz << "\n"; // reading will segfault
  // baz = new std::string("hello"); // cant just reassign
  baz.reset(new std::string("test"));

  decltype(baz) eep = unique_ptr<std::string>();
  eep = std::move(baz);
  
  // std::cout << *baz << "\n"; // will segfault
  std::cout << *eep << "\n";


  // It appears that you can however steal the reference from a
  // unique_ptr and assign it to a raw pointer.
  std::string* sneaky = &*eep;
  (*sneaky)[0] = '-';
  std::cout << *eep << "\n";
  std::cout << *sneaky << "\n";


  auto thing = unique_ptr<Thingy>(new Thingy);
  thing.reset(); // <-- destructors will be called regardless on program close
  
  return 0;
}
