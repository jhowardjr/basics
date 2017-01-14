#include <stdlib.h>
#include <stdbool.h>

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
int carray_capacity(CArray *array_ptr);
int carray_size(CArray *array_ptr);
bool carray_is_empty(CArray *array_ptr);
int carray_increase_capacity(int capacity);
int carray_decrease_capacity(int capacity);
void carray_push(CArray *array_ptr, int item);
int carray_get(CArray *array_ptr, int index);
void carray_insert(CArray *array_ptr, int index, int item);
void carray_prepend(CArray *array_ptr, int item);
int carray_pop(CArray *array_ptr);
void carray_delete(CArray *array_ptr, int index);
void carray_remove(CArray *array_ptr, int item);
int carray_find(CArray *array_ptr, int item);
void resize(CArray *array_ptr);
