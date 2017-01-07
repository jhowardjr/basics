#include <stdlib.h>

const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;

typedef struct array_t
{
  int size;
  int capacity;
  int *data;
} CArray;

CArray *carray_new(int capacity);
int carray_increase_capacity(int capacity);
void carray_push(CArray *array_ptr, int item);