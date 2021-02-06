#include <iostream>
using namespace std;
void selectionSort(int alist[], int n);

int main()
{
  int tempList[10];
  for (int i = 0; i < 10; i++)
  {
    tempList[i] = rand() % 150;
    cout << tempList[i] << " ";
  }
  cout << endl;
  selectionSort(tempList, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << tempList[i] << " ";
  }
  cout << endl;
  return 0;
}

void selectionSort(int alist[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (alist[j] < alist[minIndex])
      {
        minIndex = j;
      }
    }
    swap(alist[i], alist[minIndex]);
  }
}