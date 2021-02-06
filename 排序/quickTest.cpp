#include <iostream>
using namespace std;
void quickSort(int q[], int l, int r);

int main()
{
  int tempList[10];
  for (int i = 0; i < 10; i++)
  {
    tempList[i] = rand() % 150;
    cout << tempList[i] << " ";
  }
  cout << endl;
  quickSort(tempList, 0, 9);
  for (int i = 0; i < 10; i++)
  {
    cout << tempList[i] << " ";
  }
  cout << endl;
  return 0;
}

void quickSort(int q[], int l, int r)
{
  if (l >= r)
    return;
  int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
  while (i < j)
  {
    do
      i++;
    while (q[i] < x);
    do
      j--;
    while (q[j] > x);
    if (i < j)
      swap(q[i], q[j]);
  }
  quickSort(q, l, j);
  quickSort(q, j + 1, r);
}
