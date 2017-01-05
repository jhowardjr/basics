namespace cpp {
class CPPArray {
public:
  ~CPPArray();
  CPPArray(int capacity);
  void push(int item);
  int get(int index);
private:
  int capacity_;
  int size_;
  int *data_;
};
}