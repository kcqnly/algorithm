#include <iostream>

using namespace std;

void gapInsertionSort(int alist[], int n, int startPos, int gap);
void shellSort(int alist[], int n);
void printList(int alist[], int n);

int main()
{
  int tempList[10];
  for (int i = 0; i < 10; i++)
  {
    tempList[i] = rand() % 150;
    cout << tempList[i] << " ";
  }
  cout << endl;
  shellSort(tempList, 10);
  return 0;
}

void shellSort(int alist[], int n)
{
  int gap = n / 2;
  while (gap > 0)
  {
    for (int i = 0; i < gap; i++)
    {
      gapInsertionSort(alist, n, i, gap);
      printList(alist, 10);
    }
    gap = gap / 2;
  }
}

void gapInsertionSort(int alist[], int n, int startPos, int gap)
{
  for (int i = startPos + gap; i < n; i += gap)
  {
    for (int j = i; j > startPos; j -= gap)
    {
      if (alist[j] < alist[j - gap])
        swap(alist[j], alist[j - gap]);
      else
        break;
    }
  }
}

void printList(int alist[], int n)
{
  for (int i = 0; i < 10; i++)
  {
    cout << alist[i] << " ";
  }
  cout << endl;
}