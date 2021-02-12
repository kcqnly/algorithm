/*
 * @Author: kcqnly 
 * @Date: 2021-02-12 16:52:53 
 * @Last Modified by: kcqnly
 * @Last Modified time: 2021-02-12 17:00:04
 * @Message: AcWing 790. 数的三次方根
 */
#include <iostream>

using namespace std;

int main()
{
  double n;
  cin >> n;
  double l = -10000, r = 10000;
  const double eps = 1e-8;
  while (r - l > eps)
  {
    double mid = (l + r) / 2;
    if (mid >= n / mid / mid)
      r = mid;
    else
      l = mid;
  }
  printf("%.6lf", l);
}