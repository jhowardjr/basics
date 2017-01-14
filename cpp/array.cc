
namespace cpp
{
CPPArray::CPPArray(int capacity)
{
  size_ = 0;
  incease_capacity(capacity);
  data_ = new int[capacity_];
}

void CPPArray::incease_capacity(int capacity)
{
  capacity_ = capacity;
  if (capacity_ > kMinCapacity)
  {
    this->capacity_ *= kGrowthFactor;
  }
}

void CPPArray::push(int item)
{
  data_[size_] = item;
  size_++;
}

void CPPArray::insert(int index, int item)
{
  // TODO: RESIZE ARRAY IF NECCESSARY
  for (int i = size_; i > index; --i)
  {
    data_[i] = data_[i - 1];
  }

  data_[index] = item;
  size_++;
}

void CPPArray::deleteAt(int index)
{
  for (size_t i = index; i < size_; ++i)
  {
    data_[i] = data_[i + 1];
  }
  size_--;
}

void CPPArray::remove(int item)
{
  int i = 0;
  for (size_t j = 0; j < size_; ++j)
  {
    if (data_[j] != item)
    {
      data_[i++] = data_[j];
    }
  }

  size_ = i;
}

int CPPArray::pop()
{
  int value = data_[size_ - 1];
  size_--;
  return value;
}

void CPPArray::prepend(int item) { insert(0, item); }

int CPPArray::get_capacity() { return capacity_; }

int CPPArray::get(int index) { return data_[index]; }

int CPPArray::get_size() { return size_; }

bool CPPArray::is_empty() { return size_ == 0; }

int CPPArray::find(int item)
{
  int index = -1;
  for (size_t i = 0; i < size_; ++i)
  {
    if (data_[i] == item)
    {
      index = i;
      break;
    }
  }

  return index;
}
}