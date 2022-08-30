#include "bits/stdc++.h"
using namespace std;
bool visit[100024];
char dataa[100024];
int addr[100024];
int startStr1, beginStr2, num, tmp;
string str1, str2;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  scanf("%d %d %d", &startStr1, &beginStr2, &num);
  for (size_t i = 0; i < num; i++)
  {
    scanf("%d", &tmp);
    scanf(" %c %d", &dataa[tmp], &addr[tmp]);
  }
  while (startStr1 != -1)
  {
    visit[startStr1] = true;
    startStr1 = addr[startStr1];
  }
  while (beginStr2 != -1)
  {
    if (visit[beginStr2])
    {
      printf("%05d", beginStr2);
      return 0;
    }
    else
    {
      beginStr2 = addr[beginStr2];
    }
  }
  printf("-1");
  return 0;
}