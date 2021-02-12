/*
 * @Author: kcqnly 
 * @Date: 2021-02-12 00:46:19 
 * @Last Modified by: kcqnly
 * @Last Modified time: 2021-02-12 00:46:39
 * @Message: AcWing 788. 逆序对的数量
 */

#include <iostream>
#define N 100010
using namespace std;

int q[N], temp[N];
long long cnt;
void mergeSort(int alist[], int l, int r)
{
  if (l >= r)
    return;
  int mid = l + r >> 1;
  mergeSort(alist, l, mid), mergeSort(alist, mid + 1, r);

  int index = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r)
  {
    if (alist[i] <= alist[j])
      temp[index++] = alist[i++];
    else
    {
      temp[index++] = alist[j++];
      cnt += mid - i + 1;
    }
  }
  while (i <= mid)
    temp[index++] = alist[i++];
  while (j <= r)
    temp[index++] = alist[j++];
  for (i = l, j = 0; i <= r; i++, j++)
    alist[i] = temp[j];
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &q[i]);
  mergeSort(q, 0, n - 1);
  printf("%ld", cnt);
  return 0;
}