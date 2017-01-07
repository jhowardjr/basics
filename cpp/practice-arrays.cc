#include <iostream>
#include "array.h"
#include "array.cc"

int main()
{
  int array[5] = {0, 1, 2, 66, 4};
  std::cout << *(array + 1) << std::endl;
  cpp::CPPArray *arr = new cpp::CPPArray(17);
  arr->push(12);
  std::cout << "CPPArray capacity: " << arr->get_capacity() << std::endl;
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  std::cout << "CPPArray is_empty: " << arr->is_empty() << std::endl;
}
