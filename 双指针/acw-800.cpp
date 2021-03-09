#include <iostream>
using namespace std;
const int N = 100010;
int n, m, x;
int a[N], b[N];
int main()
{
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);
  // j倒序，i正序，从两边向结果逼近
  for (int i = 0, j = m - 1; i < n; i++)
  {
    while (j > 0 && a[i] + b[j] > x)
      j--;
    if (a[i] + b[j] == x)
      printf("%d %d", i, j);
  }
}