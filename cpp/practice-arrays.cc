#include <iostream>
#include "array.h"
#include "array.cc"

int main()
{
  int array[5] = {0, 1, 2, 66, 4};
  std::cout << *(array + 1) << std::endl;
  cpp::CPPArray *arr = new cpp::CPPArray(17);
  arr->push(12);
  arr->push(13);
  arr->push(14);
  std::cout << "CPPArray capacity: " << arr->get_capacity() << std::endl;
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  std::cout << "CPPArray is_empty: " << arr->is_empty() << std::endl;
  arr->insert(1, 99);
  std::cout << "CPPArray index 1: " << arr->get(1) << std::endl;
  std::cout << "CPPArray index 2: " << arr->get(2) << std::endl;
  std::cout << "CPPArray index 3: " << arr->get(3) << std::endl;
  arr->prepend(999);
  std::cout << "CPPArray index 2: " << arr->get(2) << std::endl;
  std::cout << "CPPArray index 0: " << arr->get(0) << std::endl;
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  std::cout << "CPPArray pop: " << arr->pop() << std::endl;
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  std::cout << "CPPArray index 2: " << arr->get(2) << std::endl;
  arr->deleteAt(2);
  std::cout << "CPPArray index 2: " << arr->get(2) << std::endl;
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  arr->prepend(99);
  arr->prepend(9);
  arr->prepend(399);
  arr->prepend(99);
  arr->prepend(90);
  arr->prepend(399);
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  arr->remove(99);
  std::cout << "CPPArray size: " << arr->get_size() << std::endl;
  for (int j = 0; j < arr->get_size(); ++j)
  {
    std::cout << "value at index " << j << " " << arr->get(j) << std::endl;
  }

  std::cout << "Find at 9 " << arr->find(9) << std::endl;
  std::cout << "Find at 45 " << arr->find(45) << std::endl;
}
