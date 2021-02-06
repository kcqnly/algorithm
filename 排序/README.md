# 排序算法笔记

## 冒泡排序

>冒泡排序的思想就是两个数之间相互比较，较大的数向后移动，较小的数向前移动，经过n轮的比较之后，每一轮下来都可以确定一个最小的数，最终达到小的数在前，大的数在后，完成排序。

优点：是稳定的排序（排序前后相同元素的相对位置不会改变）。

缺点：实打实的判断每一次，会不断地判断已经判断过得比较，导致时间冗余。

- 平均时间复杂度 $O(n^2)$
- 最坏情况 $O(n^2)$
- 最好情况      $O(n)$

```cpp
void bubbleSort(int alist[], int n)
{
  bool exchange = true;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (alist[j] > alist[j + 1])
      {
        swap(alist[j], alist[j + 1]);
      }
    }
    if (!exchange)
      break;
  }
}
```

## 选择排序

>选择排序的思路就是进行n-1轮比较，每一轮都从待选择的数组中选出最小的数出来，与交换位置交换即可。

优点：是不稳定的排序；

缺点：每一轮的比较都是独立的，所以进行了很多次重复的比较，浪费了时间。

- 平均时间复杂度 $O(n^2)$
- 最坏情况 $O(n^2)$
- 最好情况 $O(n^2)$

```cpp
void selectionSort(int alist[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (alist[j] < alist[minIndex])
      {
        minIndex = j;
      }
    }
    swap(alist[i], alist[minIndex]);
  }
}
```

## 插入排序

>它总是保持一个位置靠前的 已排好的子表，然后每一个新的数据项被 “插入” 到前边的子表里，排好的子表增加一项。我们认为只含有一个数据项的列表是已经排好的。每排后面一个数据（从 1 开始到 n-1），这 个的数据会和已排好子表中的数据比较。比较时，我们把之前已经排好的列表中比这个数据大的移到它的右边。当子表数据小于当前数据，或者当前数据已经和子表的所有数据比较了时，就可 以在此处插入当前数据项。

- 稳定
- 平均时间复杂度 $O(n^2)$
- 最坏情况 $O(n^2)$
- 最好情况 $O(n)$

```cpp
void insertionSort(int alist[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j > 0; j--)
    {
      if (alist[j] < alist[j - 1])
        swap(alist[j], alist[j - 1]);
      else
        break;
    }
  }
}
```

## 希尔排序

>希尔排序有时又叫做 “缩小间隔排序”，它以插入排序为基础，将原来要排序的列表划分为一些子列表，再对每一个子列表执行插入排序，从而实现对插入排序性能的改进。划分子列的特定方法是希尔排序的关键。我们并不是将原始列表分成含有连续元素的子列，而是确定一个划分列表的增量 “i”，这个i更准确地说，是划分的间隔。然后把每间隔为i的所有元素选出来组成子列表，然后对每个子序列进行插入排序，最后当 i=1 时，对整体进行一次直接插入排序。

- 不稳定
- 平均时间复杂度 $O(n^{1.5})$
- 最坏情况 $O(n^2)$
- 最好情况 $O(n)$

```cpp
void shellSort(int alist[], int n)
{
  int gap = n / 2;
  while (gap > 0)
  {
    for (int i = 0; i < gap; i++)
    {
      gapInsertionSort(alist, n, i, gap);
    }
    gap = gap / 2;
  }
}

void gapInsertionSort(int alist[], int n, int startPos, int gap)
{
  for (int i = startPos + gap; i < n; i += gap)
  {
    for (int j = i; j > startPos; j -= gap)
    {
      if (alist[j] < alist[j - gap])
        swap(alist[j], alist[j - gap]);
      else
        break;
    }
  }
}
```

## 快速排序

1. 确定分界点 ：可以选择左边界`q[l]`、中间点`q[(l+r)/2]`、右边界`q[r]`，也可以随机取。

2. 调整区间，将区间分为`<=x`和`>=x`两部分。

3. 递归处理左右两段。

```cpp
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
```

- 不稳定
- 平均时间复杂度 $O(nlogn)$
- 最坏情况 $O(n^2)$
- 最好情况 $O(nlogn)$

## 归并排序

- 确定分界点（中间点）
- 递归排序左边和右边
- 归并（合二为一）

```cpp
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid),merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}
```

- 稳定
- 平均时间复杂度 $O(nlogn)$
- 最坏情况 $O(nlogn)$
- 最好情况 $O(nlogn)$
