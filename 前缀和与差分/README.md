# 前缀和与差分

## 一维前缀和

```text
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]
```

例：[acwing-795](https://www.acwing.com/problem/content/description/797/)

```c++
#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int a[N], s[N];

int main()
{
  cin >> n >> m;
  // 让i从1到n，是为了方便使用s[i]=s[i-1]+a[i]的公式
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
  while (m--)
  {
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
  }
}

```

## 二维前缀和

```
S[i, j] = 第i行j列格子左上部分所有元素的和
以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
```

例如：[acwing-796](https://www.acwing.com/problem/content/description/798/)

```c++
#include <iostream>

using namespace std;
int n, m, q;
const int N = 1010;
int a[N][N], s[N][N];
int main()
{
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  }
  while (q--)
  {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
  }
}
```

