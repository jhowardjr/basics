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
  void insert(int index, int item);
  void prepend(int item);
  void deleteAt(int index);
  int pop();
  int get(int index);
  int get_capacity();
  int get_size();
  bool is_empty();

private:
  int capacity_;
  int size_;
  int *data_;
  void incease_capacity(int capacity);
};
}