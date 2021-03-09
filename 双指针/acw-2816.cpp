#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, m;
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);
  int j = 0;
  for (int i = 0; i < m; i++)
  {
    if (j < n && a[j] == b[i])
      j++;
  }
  if (j == n)
    printf("Yes\n");
  else
    printf("No\n");
}