#include <iostream>

using namespace std;

void insertionSort(int alist[], int n);

int main()
{
  int tempList[10];
  for (int i = 0; i < 10; i++)
  {
    tempList[i] = rand() % 100;
    cout << tempList[i] << " ";
  }
  cout << endl;
  insertionSort(tempList, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << tempList[i] << " ";
  }
  cout << endl;
  return 0;
}

void insertionSort(int alist[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j > 0; j--)
    {
      if (alist[j] < alist[j - 1])
        swap(alist[j], alist[j - 1]);
      else
        break;
    }
  }
}