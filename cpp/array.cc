
namespace cpp {
CPPArray::CPPArray(int capacity) {
  size_ = 0;
  capacity_ = capacity;
  data_ = new int[capacity];
}

void CPPArray::push(int item) {
  data_[size_] = item;
  size_++;
}

int CPPArray::get(int index) { return data_[index]; }

}