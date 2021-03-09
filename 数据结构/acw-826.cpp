#include <iostream>

using namespace std;
const int N = 100010;
// head存储链表头
//e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
  head = -1;
  idx = 0;
}

void addToHead(int x)
{
  e[idx] = x;
  ne[idx] = head;
  head = idx;
  idx++;
}

// 将x插入到下标是K的点后面
void add(int k, int x)
{
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx;
  idx++;
}

// 将下标是K的点后面的点删掉
void remove(int k)
{
  ne[k] = ne[ne[k]];
}

int main()
{
  int n;
  cin >> n;
  init();
  while (n--)
  {
    string op;
    int k, x;
    cin >> op;
    if (op == "H")
    {
      cin >> x;
      addToHead(x);
    }
    else if (op == "D")
    {
      cin >> k;
      if (!k)
        head = ne[head];
      remove(k - 1);
    }
    else if (op == "I")
    {
      cin >> k >> x;
      add(k - 1, x);
    }
  }
  for (int i = head; i != -1; i = ne[i])
  {
    cout << e[i] << ' ';
  }
  cout << endl;
  return 0;
}