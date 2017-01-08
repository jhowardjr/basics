
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

  for (int i = index; i <= size_ - 1; i++)
  {
    data_[size_ - i + 1] = data_[size_ - i];
  }

  data_[index] = item;
  size_++;
}

int CPPArray::pop()
{
  int value = data_[size_ - 1];
  size_--;
  return value;
}

void CPPArray::prepend(int item)
{
  insert(0, item);
}

int CPPArray::get_capacity() { return capacity_; }

int CPPArray::get(int index) { return data_[index]; }

int CPPArray::get_size() { return size_; }

bool CPPArray::is_empty() { return size_ == 0; }
}