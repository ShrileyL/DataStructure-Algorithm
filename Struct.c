#include <iostream>
using namespace std;

template <typename E> class List
{
private:
  void operator = (const List&) {}
  List (cons List&) {}
public:
  List() {}
  virtual ~List() {}
  virtual void clear() = 0;
  virtual void insert(const E& item) = 0;
  virtual void append(const E& item) = 0;
  virtual E remove() = 0;
  virtual void moveToStart() = 0;
  virtual void moveToEnd() = 0;
  virtual void prev() = 0;
  virtual void next() = 0;
  virtual int length() = 0;
  virtual int currPos() = 0;
  virtual void moveToPos (int pos) = 0;
  virtual const E& getValue() const = 0;

};

template <typename E> 
class AList : public List<E>
{
private:
  int maxSize;
  int listSize;
  int curr;
  E* listArray;
  
piblic:
  Alist(int size = 20)
  {
  maxSize = size;
  listSize = curr = 0;
  listArray = new E[maxSize];
  };
  
  ~Alist() {delete [] listArray};
  
  void clear()
  {
  delete [] listArray;
  listSize = curr = 0;
  istArray = new E[maxSize];
  };
  
  void insert(const E& it)
  {
  Assert(listSize< maxSize,"List capacity exceeded");
  for(int i=listSize;i > curr;i--)
    lisArray[i]=listArray[i-1];
   listArray[curr] = it;
   listSize++;
  };
  
  void append(const E& it) 
  {
  Assert(listSize< maxSize,"List capacity exceeded");
  listArray[listSize++] = it;
  };
  
  E remove()
  {
  Assert((curr>=0) && (curr < listSize),"No element");
  E it = listArray[curr];
  for(int i=curr; i <listSze-1;i++)
    listArray[i]=listArray[i+1];
  listSize--;
  return it;
  };
  
  void moveToStart() {curr = 0;};
  
  void moveToEnd() {curr = listSize};
  
  void prev(){if (curr !=0) curr--;};
  
  void next(){if (curr!<listSize) curr++ };
  
  int length() const{return listSize};
  int currPos() const{return curr};
  void moveToPos (int pos) {
  Assert((pos>=0) && (pos < =listSize),"Pos out of range");
  curr = pos;
  };
  const E& getValue() const {
  Assert((curr>=0) && (curr < listSize),"No current element");
  return listArray[curr];
  };
  
};

int main()
{
 Alist Al;

  return 0;
}