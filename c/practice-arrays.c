#include <stdio.h>
#include "array.h"
#include "array.c"

int main()
{
  int values[10] = {0, 1, 2, 3, 88, 5, 6, 7, 8, 9};

  printf("%d\n", *(values + 4));
  printf("%d\n", values[4]);
  int capacity = 17;

  CArray *array_ptr = carray_new(capacity);

  for (int i = 0; i < capacity; i++)
  {
    carray_push(array_ptr, i);
  }

  printf("%d\n", array_ptr->capacity);
  return 0;
}
