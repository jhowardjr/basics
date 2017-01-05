#include <stdlib.h>

typedef struct array_t {
  int size;
  int capacity;
  int *data;
} CArray;

CArray *carray_new(int capacity);

void carray_push(CArray *array_ptr, int item);