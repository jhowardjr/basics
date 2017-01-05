#include <iostream>
#include "array.h"
#include "array.cc"

int main() {
  int array[5] = {0, 1, 2, 66, 4};
  std::cout << *(array + 1) << std::endl;
  cpp::CPPArray *arr = new cpp::CPPArray(11);
  arr->push(12);
  std::cout << arr->get(0) << std::endl;
}
