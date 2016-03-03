#include <iostream>
#include <stdlib.h>


int add (int lhs, int rhs) {
  return lhs + rhs;
}

int sub (int lhs, int rhs) {
  return lhs - rhs;
}

int mul (int lhs, int rhs) {
  return lhs * rhs;
}


typedef int (*mathop)(int, int);


mathop random_operation () {
  mathop ret;
  switch (rand() % 3) {
  case 0:
    ret = add;
    break;
  case 1:
    ret = sub;
    break;
  case 2:
    ret = mul;
    break;
  }
  return ret;
}


int main() {
  int op_count = 5;
  mathop script[op_count];
  for (int i=0; i<op_count; i+=1) {
    script[i] = random_operation();
  }

  int acc = 10;
  int noise;
  for (int i=0; i<op_count; i+=1) {
    noise = rand() % 100;
    
    std::cout << acc << " [?] " << noise << " == ";
    acc = script[i](acc, noise);
    std::cout << acc << "\n";
  }
  return 0;
}
