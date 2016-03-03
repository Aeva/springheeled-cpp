#include <iostream>
#include <memory>


/*
 *  To build:
 *
 *  > g++ -std=c++11 basecode.cpp
 *
 */


using std::cout;
using std::shared_ptr;


class BaseClass {
public:
  BaseClass() {
    cout << "base class initializer called\n";
  };
  BaseClass(int foo) {
    cout << "special base class initializer called\n";
  };
  ~BaseClass() {
    cout << "base class destructor called\n";
  };
  virtual void splorf () {
    cout << "base class splorfed\n";
  };
};


class ChildClass : public BaseClass {
public:
  ChildClass() : BaseClass(10) {
    cout << "derived class initializer called\n";
  };
  ~ChildClass() {
    cout << "derived class destructor called\n";
  };
  void splorf () override {
    cout << "child class splorfed\n";
  };
};



int main() {
  auto foo = shared_ptr<BaseClass>(new ChildClass);
  foo->splorf();
  foo.reset();
  return 0;
}
