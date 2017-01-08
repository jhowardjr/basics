
CArray *carray_new(int capacity)
{

  /*
  *  allocates size bytes and returns a pointer to the allocated memory
  */
  CArray *array_ptr = malloc(sizeof(CArray));

  array_ptr->size = 0;

  /*
  *  increase the initial capacity by a factor of 2 if necessary
  */
  array_ptr->capacity = carray_increase_capacity(capacity);

  /*
  *  allocates 16 bytes times the given capacity
  */
  array_ptr->data = (int *)malloc(sizeof(int) * array_ptr->capacity);

  /*
  *  returns address of initialized CArray
  */
  return array_ptr;
}

int carray_capacity(CArray *array_ptr)
{
  return array_ptr->capacity;
}

int carray_size(CArray *array_ptr)
{
  return array_ptr->size;
}

bool carray_is_empty(CArray *array_ptr)
{
  return array_ptr->size == 0;
}

int carray_increase_capacity(int capacity)
{
  int allocated_capacity = capacity;

  if (capacity > kMinCapacity)
  {
    allocated_capacity *= kGrowthFactor;
  }

  return allocated_capacity;
}

void carray_push(CArray *array_ptr, int item)
{
  *(array_ptr->data + array_ptr->size) = item;
  array_ptr->size++;
}

int carray_get(CArray *array_ptr, int index)
{
  return *(array_ptr->data + index);
}

void carray_insert(CArray *array_ptr, int index, int item)
{
  // TODO: RESIZE ARRAY IF NECCESSARY

  for (int i = array_ptr->size; i > index; --i)
  {
    *(array_ptr->data + i) = *(array_ptr->data + i - 1);
  }

  *(array_ptr->data + index) = item;

  array_ptr->size++;
}

void carray_prepend(CArray *array_ptr, int item)
{
  carray_insert(array_ptr, 0, item);
}

int carray_pop(CArray *array_ptr)
{
  int value = *(array_ptr->data + array_ptr->size - 1);
  array_ptr->size--;
  return value;
}
