#include <iostream>
#include <memory>


/*
 *  To build:
 *
 *  > g++ -std=c++11 shared_ptr.cpp
 *
 */


using std::shared_ptr;
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
  shared_ptr<Thingy> foo(new Thingy);
  auto bar = foo;
  auto baz = foo;

  std::cout << "clearing foo...\n";
  foo.reset();
  std::cout << "clearing bar...\n";
  bar.reset();
  std::cout << "clearing baz...\n";
  baz.reset();
  std::cout << "exiting program...\n";
  
  return 0;
}
