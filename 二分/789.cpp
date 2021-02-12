/*
 * @Author: kcqnly 
 * @Date: 2021-02-12 14:45:07 
 * @Last Modified by:   kcqnly 
 * @Last Modified time: 2021-02-12 14:45:07 
 * @Message: AcWing 789. 数的范围
 */

#include <iostream>
using namespace std;
const int N = 100010;

int n, q;
int alist[N];

int main()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", &alist[i]);
  while (q--)
  {
    int x;
    scanf("%d", &x);
    int l = 0, r = n - 1;
    while (l < r)
    {
      int mid = l + r >> 1;
      if (alist[mid] >= x)
        r = mid;
      else
        l = mid + 1;
    }
    if (alist[l] != x)
      cout << "-1 -1" << endl;
    else
    {
      cout << l << ' ';
      int l = 0, r = n - 1;
      while (l < r)
      {
        int mid = l + r + 1 >> 1;
        if (alist[mid] <= x)
        {
          l = mid;
        }
        else
        {
          r = mid - 1;
        }
      }
      cout << l << endl;
    }
  }
}