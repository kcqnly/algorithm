/*
 * @Author: kcqnly 
 * @Date: 2021-02-13 14:45:03 
 * @Last Modified by: kcqnly
 * @Last Modified time: 2021-02-13 14:49:32
 * @Message: 双指针测试，将输入字符，通过空格分割并输出
 */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  int n = str.length();
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j < n && str[j] != ' ')
      j++;
    for (int k = i; k < j; k++)
      cout << str[k];
    cout << endl;
    i = j;
  }
}