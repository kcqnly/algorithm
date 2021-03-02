# 二分

- 适用于有序序列
- 时间复杂度 $O(logn)$

## 整数二分

```cpp
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

### 注意事项

1、为什么模版二在计算mid的时候会+1？

当`l = r-1`时，`mid = (l + r)/2`，所以mid=l，那么就会导致区间的范围没有变化，从而导致死循环。

2、 如何选择模版？
根据`check`函数，分析结果所在的区间，判断是`l = mid`，还是`r = mid`，从而选择相应的模版。

## 浮点数二分

```cpp
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

### 精度选择

比题目要求的精度高两位，例如题目要求6位小数，eps为1e-8
