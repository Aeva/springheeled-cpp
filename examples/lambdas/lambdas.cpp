#include <iostream>
#include <algorithm>
#include <memory>
#include <deque>


/*
 *  To build:
 *
 *  > g++ -std=c++11 lambdas.cpp
 *
 */


using std::shared_ptr;
using std::deque;
using std::cout;


class Thing {
public:
  int x = 0;
  int y = 0;
  Thing(int _x, int _y) {
    x = _x;
    y = _y;
  }
};


int main() {
  auto container = deque<Thing>();
  container.push_back(Thing(10, 10));
  container.push_back(Thing(10, 20));
  container.push_back(Thing(20, 10));
  container.push_back(Thing(20, 20));

  auto ands = shared_ptr<deque<Thing>>(new deque<Thing>());
  auto nots = shared_ptr<deque<Thing>>(new deque<Thing>());

  auto closure = [ands, nots](Thing ct) {
    if (ct.x == ct.y) {
      (*ands).push_back(ct);
    }
    else {
      (*nots).push_back(ct);
    }
    return;
  };
  
  std::for_each(container.begin(), container.end(), closure);


  cout << "Things where x == y:\n";
  for (auto item : *ands) {
    cout << " - x: " << item.x << ", y: " << item.y << "\n";
  }


  cout << "\nThings where x != y:\n";
  for (auto item : *nots) {
    cout << " - x: " << item.x << ", y: " << item.y << "\n";
  }
  
  return 0;
}
