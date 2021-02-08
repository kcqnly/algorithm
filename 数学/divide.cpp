/*
 * @Author: kcqnly 
 * @Date: 2021-02-08 16:17:33 
 * @Last Modified by: kcqnly
 * @Last Modified time: 2021-02-08 16:58:34
 * @Message: AcWing 867. 分解质因数
 */

#include <iostream>

using namespace std;

void divide(int n)
{
  for (int i = 2; i <= n / i; i++)
  {
    if (n % i == 0)
    {
      int s = 0;
      while (n % i == 0)
      {
        n /= i;
        s++;
      }
      printf("%d %d\n", i, s);
    }
  }
  if (n > 1)
    printf("%d %d\n", n, 1);
  puts("");
}

int main()
{
  int n;
  scanf("%d", &n);
  while (n--)
  {
    int temp;
    scanf("%d", &temp);
    divide(temp);
  }
}