#include "bits/stdc++.h"
using namespace std;

struct Node
{
  int addr, value;
} store[100024];
int num, k, startAddr;
vector<Node> former, nowadays, later;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> startAddr >> num >> k;
  for (size_t i = 0; i < num; i++)
  {
    int tmpIndex;
    cin >> tmpIndex;
    cin >> store[tmpIndex].value >> store[tmpIndex].addr;
  }
  if (startAddr == -1)
  {
    printf("-1");
    return 0;
  }
  while (startAddr != -1)
  {
    Node tmp;
    tmp.value = store[startAddr].value;
    tmp.addr = startAddr;
    if (tmp.value < 0)
      former.push_back(tmp);
    else if (tmp.value <= k)
      nowadays.push_back(tmp);
    else
      later.push_back(tmp);
    startAddr = store[startAddr].addr;
  }
  former.insert(former.end(), nowadays.begin(), nowadays.end());
  former.insert(former.end(), later.begin(), later.end());
  for (size_t i = 0; i < former.size(); i++)
  {
    printf("%05d %d ", former[i].addr, former[i].value);
    if (i != former.size() - 1)
    {
      printf("%05d\n", former[i + 1].addr);
    }
    else
    {
      printf("-1");
    }
  }
  return 0;
}