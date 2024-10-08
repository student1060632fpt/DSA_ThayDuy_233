#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
  static void printArray(T *start, T *end)
  {
    int size = end - start;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << " ";
    cout << start[size - 1];
    cout << endl;
  }
  //---START---
  static void merge(T *start, T *middle, T *end)
  {
    // TODO
    T *left = start;
    T *right = end;
    T i, j, k;
    T n1 = middle - left + 1;
    T n2 = right - middle;
    /* Tạo các mảng tạm */
    T *L = new T[n1], *R = new T[n2];
    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
      L[i] = left[i];
    for (j = 0; j < n2; j++)
      R[j] = middle[1 + j];

    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = 0; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
      {
        left[k] = L[i];
        i++;
      }
      else
      {
        left[k] = R[j];
        j++;
      }
      k++;
    }

    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
      left[k] = L[i];
      i++;
      k++;
    }

    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
      left[k] = R[j];
      j++;
      k++;
    }
    //	delete L, R;
  }

public:
  static void InsertionSort(T *start, T *end)
  {
    // TODO
    for (int i = 0; i < end - start; i++)
    {
      char min = start[i];
      int id = i;
      for (int j = i; j < end - start; j++)
      {
        if (start[j] < min)
        {
          id = j;
          min = start[j];
        }
      }
      int temp = start[i];
      start[i] = start[id];
      start[id] = temp;
    }
  }

  static void TimSort(T *start, T *end, int min_size)
  {
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    cout << "Insertion Sort: ";
    for (int i = 0; i < end - start; i += min_size)
    {
      if (start + i + min_size < end)
        InsertionSort(start + i, start + i + min_size);
      else
        InsertionSort(start + i, end);
    }
    printArray(start, end);
    int i = 1;
    for (int size = min_size; size < end - start; size = 2 * size)
    {
      for (int left = 0; left < end - start; left += 2 * size, i++)
      {
        cout << "Merge " << i << ": ";
        int mid = (left + size - 1) < (end - start - 1) ? (left + size - 1) : (end - start - 1);
        int right = (left + 2 * size - 1) < (end - start - 1) ? (left + 2 * size - 1) : (end - start - 1);
        merge(&start[left], &start[mid], &start[right]);
        printArray(start, end);
      }
    }
  }
};
//---END---
int main()
{
  int array[] = {19, 20, 18, 17, 12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3};
  int min_size = 4;
  Sorting<int>::TimSort(&array[0], &array[20], min_size);
  // Insertion Sort: 17 18 19 20 12 13 14 15 1 2 6 9 4 7 11 16 3 5 8 10
  // Merge 1: 12 13 14 15 17 18 19 20 1 2 6 9 4 7 11 16 3 5 8 10
  // Merge 2: 12 13 14 15 17 18 19 20 1 2 4 6 7 9 11 16 3 5 8 10
  // Merge 3: 12 13 14 15 17 18 19 20 1 2 4 6 7 9 11 16 3 5 8 10
  // Merge 4: 1 2 4 6 7 9 11 12 13 14 15 16 17 18 19 20 3 5 8 10
  // Merge 5: 1 2 4 6 7 9 11 12 13 14 15 16 17 18 19 20 3 5 8 10
  // Merge 6: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  return 0;
}
