
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

int CPPArray::get_capacity() { return capacity_; }

int CPPArray::get(int index) { return data_[index]; }

int CPPArray::get_size() { return size_; }

bool CPPArray::is_empty() { return size_ == 0; }
}