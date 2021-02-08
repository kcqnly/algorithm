/*
 * @Author: kcqnly 
 * @Date: 2021-02-08 16:07:25 
 * @Last Modified by:   kcqnly 
 * @Last Modified time: 2021-02-08 16:07:25 
 * @Message: AcWing 866. 试除法判定质数 
 */
#include <iostream>
using namespace std;

bool isPrime(int x)
{
  if (x < 2)
    return false;
  for (int i = 2; i <= x / i; i++)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (isPrime(x))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}