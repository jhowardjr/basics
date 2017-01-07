
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
