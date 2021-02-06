#include <iostream>

using namespace std;

void bubbleSort(int alist[], int n);

int main()
{
  int tempList[10];
  for (int i = 0; i < 10; i++)
  {
    tempList[i] = rand() % 100;
    cout << tempList[i] << " ";
  }
  cout << endl;
  bubbleSort(tempList, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << tempList[i] << " ";
  }
  cout << endl;
  return 0;
}

void bubbleSort(int alist[], int n)
{
  bool exchange = true;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (alist[j] > alist[j + 1])
      {
        swap(alist[j], alist[j + 1]);
      }
    }
    if (!exchange)
      break;
  }
}