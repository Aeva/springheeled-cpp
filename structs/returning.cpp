#include <iostream>


struct WonderStruct {
  char *name;
  char *value;
};


WonderStruct combiner(WonderStruct *lhs, WonderStruct *rhs) {
  return {lhs->name, rhs->value};
}


WonderStruct* combiner2(WonderStruct *lhs, WonderStruct *rhs) {
  // 'out' will only exist within the function's scope, and the
  // subsequent print will segfault.
  WonderStruct out = {lhs->name, rhs->value};
  return &out;
}


WonderStruct* combiner3(WonderStruct *lhs, WonderStruct *rhs) {
  WonderStruct *out = new WonderStruct {lhs->name, rhs->value};
  return out;
}


void print(WonderStruct *chump) {
  std::cout << "Today we review " << chump->name << ".\n"
            << "It has been said that " << chump->name
            << "'s value as a human being is\n" << chump->value << ".\n\n";
}


int main() {
  WonderStruct chump_a = {"Aeva", "something she judges too harshly"};
  WonderStruct chump_b = {"Correct Horse", "dubious at best"};
  WonderStruct mashup = combiner(&chump_a, &chump_b);
  print(& mashup);
  WonderStruct *mashup2 = combiner3(&chump_b, &chump_a);
  print(mashup2);
  delete mashup2;
  return 0;
}
