#include "bits/stdc++.h"
using namespace std;
bool visit[100024];
struct Node
{
  int value, next;
} store[100024], temp;
vector<Node> first, second;
int startAddr, num;
void process(vector<Node> &asd)
{
  if (!asd.size())
  {
    return;
  }
  for (size_t i = 0; i < asd.size(); i++)
  {
    printf("%05d %d ", asd[i].next, asd[i].value);
    if (i != asd.size() - 1)
    {
      printf("%05d\n", asd[i + 1].next);
    }
    else
    {
      printf("-1\n");
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> startAddr >> num;
  for (size_t i = 0; i < num; i++)
  {
    int tmpIndex;
    cin >> tmpIndex;
    cin >> store[tmpIndex].value >> store[tmpIndex].next;
  }
  while (startAddr != -1)
  {
    temp.next = startAddr;
    temp.value = store[startAddr].value;
    if (visit[abs(temp.value)])
    {
      second.push_back(temp);
    }
    else
    {
      visit[abs(temp.value)] = true;
      first.push_back(temp);
    }
    startAddr = store[startAddr].next;
  }
  process(first);
  process(second);
  return 0;
}