
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

int carray_capacity(CArray *array_ptr) { return array_ptr->capacity; }

int carray_size(CArray *array_ptr) { return array_ptr->size; }

bool carray_is_empty(CArray *array_ptr) { return array_ptr->size == 0; }

int carray_increase_capacity(int capacity)
{
  int allocated_capacity = capacity;

  if (capacity > kMinCapacity)
  {
    allocated_capacity *= kGrowthFactor;
  }

  return allocated_capacity;
}

int carray_decrease_capacity(int capacity)
{
  int allocated_capacity = capacity;

  if (capacity > kMinCapacity * kGrowthFactor)
  {
    allocated_capacity /= kGrowthFactor;
  }

  return allocated_capacity;
}

void carray_push(CArray *array_ptr, int item)
{
  resize(array_ptr);

  *(array_ptr->data + array_ptr->size) = item;

  array_ptr->size++;
}

int carray_get(CArray *array_ptr, int index)
{
  return *(array_ptr->data + index);
}

void carray_insert(CArray *array_ptr, int index, int item)
{
  resize(array_ptr);

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
  if (array_ptr->size == 0)
  {
    exit(EXIT_FAILURE);
  }

  resize(array_ptr);

  int value = *(array_ptr->data + array_ptr->size - 1);
  array_ptr->size--;
  return value;
}

void carray_delete(CArray *array_ptr, int index)
{
  resize(array_ptr);

  for (size_t i = index; i < array_ptr->size; ++i)
  {
    *(array_ptr->data + i) = *(array_ptr->data + i + 1);
  }

  array_ptr->size--;
}

void carray_remove(CArray *array_ptr, int item)
{
  resize(array_ptr);

  int i = 0;
  for (int j = 0; j < array_ptr->size; j++)
  {
    if (*(array_ptr->data + j) != item)
    {
      // COPY VALUE TO ARRAY IF IT DOESN'T EQUAL THE ITEM
      // INCREASE THE SIZE
      *(array_ptr->data + i++) = *(array_ptr->data + j);
    }
  }

  //STORE THE size
  array_ptr->size = i;
}

int carray_find(CArray *array_ptr, int item)
{
  int index = -1;

  for (int i = 0; i < array_ptr->size; i++)
  {
    if (*(array_ptr->data + i) == item)
    {
      index = i;
      break;
    }
  }

  return index;
}

void resize(CArray *array_ptr)
{
  int current_capacity = array_ptr->capacity;
  int new_capacity = current_capacity;
  
  if (current_capacity == array_ptr->size)
  {
    new_capacity = carray_increase_capacity(current_capacity);
  }
  else if (array_ptr->size == (current_capacity / 4))
  {
    new_capacity = carray_decrease_capacity(current_capacity);
  }

  int *new_data = (int *)malloc(sizeof(int) * new_capacity);

  for (int i = 0; i < current_capacity; ++i)
  {
    *(new_data + i) = *(array_ptr->data + i);
  }

  array_ptr->data = new_data;
  array_ptr->capacity = new_capacity;
}