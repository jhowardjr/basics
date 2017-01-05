
CArray *carray_new(int capacity) {
  CArray *array_ptr = malloc(sizeof(CArray));
  array_ptr->size = 0;
  array_ptr->capacity = capacity;
  array_ptr->data = (int *)malloc(sizeof(int) * capacity);
  return array_ptr;
}

void carray_push(CArray *array_ptr, int item) {
  *(array_ptr->data + array_ptr->size) = item;
  array_ptr->size++;
}