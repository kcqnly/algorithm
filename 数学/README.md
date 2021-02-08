# 数学知识

## 素数

### 试除法判定质数

```cpp
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
```

时间复杂度 $O(\sqrt{n})$

### 分解质因数

n当中至多只包含一个大于sqrt(n)的质因子。

```cpp
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
```

时间复杂度 $O(\sqrt{n})$

### 埃式筛法求素数

```cpp
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
```

时间复杂度 $O(nloglogn)$

### 线性筛法

n只会被它的最小质因子筛掉。

```cpp
int primes[N], cnt; // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

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
```
