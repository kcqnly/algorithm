/*
 * @Author: kcqnly 
 * @Date: 2021-02-08 17:36:34 
 * @Last Modified by: kcqnly
 * @Last Modified time: 2021-02-08 20:23:26
 * @Message: AcWing 868. 筛质数
 */
#include <iostream>
#include <vector>
#define N 1000010
using namespace std;

int primes[N], cnt; // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

// 朴素筛法求素数
void get_primes1(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!st[i])
    {
      primes[cnt++] = i;
      for (int j = i + i; j <= n; j += i)
      {
        st[j] = true;
      }
    }
  }
}

// 线性筛法 数组写法
void get_primes2(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!st[i])
      primes[cnt++] = i;
    // 从小到大枚举所有质数
    for (int j = 0; primes[j] <= n / i; j++)
    {
      // 把当前质数和i的乘积筛掉
      st[primes[j] * i] = true;
      if (i % primes[j] == 0)
        break;
      // 这句话执行就意味这primes[j]一定是i的最小质因子
      // primes[j]也一定是primes[j]*i的最小质因子
    }
  }
}

// 线性筛法 vector写法
int get_primes3(int n)
{
  vector<int> primes;
  vector<bool> st(n, false);
  for (int i = 2; i <= n; i++)
  {
    if (!st[i])
      primes.push_back(i);
    for (int j = 0; primes[j] <= n / i; j++)
    {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
  return primes.size();
}

int main()
{
  int n;
  cin >> n;
  get_primes2(n);
  cout << cnt << endl;
}