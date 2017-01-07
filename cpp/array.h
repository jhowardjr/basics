namespace cpp
{
const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;
class CPPArray
{
public:
  ~CPPArray();
  CPPArray(int capacity);
  void push(int item);
  int get(int index);
  int get_capacity();

private:
  int capacity_;
  int size_;
  int *data_;
  void incease_capacity(int capacity);
};
}