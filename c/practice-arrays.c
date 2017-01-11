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
  printf("array_ptr at index at 3: %d\n", carray_get(array_ptr, 3));
  carray_insert(array_ptr, 3, 99);
  printf("array_ptr at index at 3: %d\n", carray_get(array_ptr, 3));
  printf("array_ptr at index at 4: %d\n", carray_get(array_ptr, 4));
  printf("array_ptr at index at 17: %d\n", carray_get(array_ptr, 17));
  carray_prepend(array_ptr, 999);
  printf("array_ptr at index at 0: %d\n", carray_get(array_ptr, 0));
  printf("array_ptr size: %d\n", carray_size(array_ptr));
  printf("array_ptr pop: %d\n", carray_pop(array_ptr));
  printf("array_ptr size: %d\n", carray_size(array_ptr));
  printf("array_ptr at index at 2: %d\n", carray_get(array_ptr, 2));
  carray_delete(array_ptr, 2);
  printf("array_ptr at index at 2: %d\n", carray_get(array_ptr, 2));
  printf("array_ptr size: %d\n", carray_size(array_ptr));
  return 0;
}
