#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList
{
public:
  class Node; // Forward declaration
protected:
  Node *head;
  Node *tail;
  int count;

public:
  SLinkedList()
  {
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
  }
  ~SLinkedList(){};
  void add(T e)
  {
    Node *pNew = new Node(e);

    if (this->count == 0)
    {
      this->head = this->tail = pNew;
    }
    else
    {
      this->tail->next = pNew;
      this->tail = pNew;
    }

    this->count++;
  }
  int size()
  {
    return this->count;
  }
  void printList()
  {
    stringstream ss;
    ss << "[";
    Node *ptr = head;
    while (ptr != tail)
    {
      ss << ptr->data << ",";
      ptr = ptr->next;
    }

    if (count > 0)
      ss << ptr->data << "]";
    else
      ss << "]";
    cout << ss.str() << endl;
  }

public:
  class Node
  {
  private:
    T data;
    Node *next;
    friend class SLinkedList<T>;

  public:
    Node()
    {
      next = 0;
    }
    Node(T data)
    {
      this->data = data;
      this->next = nullptr;
    }
  };

  void bubbleSort();
};
template <class T>
void SLinkedList<T>::bubbleSort()
{
  int current = this->count - 1;
  bool flag = false;
  int swap = 0;
  while (current > 0 && flag == false)
  {
    int walker = 0; // vậy khác gì tail
    flag = true;
    while (walker < current)
    {
      // lấy data walker
      if (this->head == nullptr)
        return;

      Node *temp = this->head;
      int i = 0;
      while (i < walker)
      {

        temp = temp->next;
        i++;
      }
      if (temp->data > temp->next->data)
      {
        flag = false;
        // swap
        swap++;
        T swapData = temp->data;
        temp->data = temp->next->data;
        temp->next->data = swapData;
      }
      walker = walker + 1;
    }
    current = current - 1;
    cout<<swap<<endl;
    this->printList();
  }
}
int main()
{
  int arr[] = {6,4,8,1,3};
  SLinkedList<int> list;
  for (int i = 0; i < int(sizeof(arr)) / 4; i++)
    list.add(arr[i]);
  list.bubbleSort();
  // [2,8,4,1,9]
  // [2,4,1,8,9]
  // [2,1,4,8,9]
  // [1,2,4,8,9]
  return 0;
}
