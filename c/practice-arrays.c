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

  printf("array_ptr size: %d\n", carray_size(array_ptr));
  printf("array_ptr capacity: %d\n", carray_capacity(array_ptr));
  printf("array_ptr is_empty: %d\n", carray_is_empty(array_ptr));
  printf("array_ptr at index: %d\n", carray_get(array_ptr, 3));
  return 0;
}
