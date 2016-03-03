#include <iostream>

/*
 * You can initialize a struct with the {"this", "that"} syntax, or
 * with a constructor, but you cannot do both in the same program.  In
 * what follows, you can comment out the constructor function and
 * toggle the comments in the 'main' function, and it should still
 * work.
 */


struct WonderStruct {
  char *name;
  char *value;

  WonderStruct () {
    name = "Saint Norbert, the Hungry";
    value = "dubious at best";
  }
};


void print(WonderStruct *chump) {
  std::cout << "Today we review " << chump->name << ".\n"
            << "It has been said that " << chump->name
            << "'s value as a human being is\n" << chump->value << ".\n";
}


int main() {
  WonderStruct chump_a = WonderStruct();
  //WonderStruct chump_b = {"Aeva", "something she judges too harshly"};
  print(& chump_a);
  //print(& chump_b);
  return 0;
}
