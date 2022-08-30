#include "bits/stdc++.h"
using namespace std;
int father[40], num, lastNode = -2; //lastnode record the lastnode.
string tmp;                         //Can not use char type. the node number can greater than 9;
bool visit[40];
int charToNumber(string s)
{
  int ans = 0;
  for (size_t i = 0; i < s.size(); i++)
  {
    ans = ans * 10 + (int)(s[i] - '0');
  }
  return ans;
}
struct Node
{
  int leftChild, rightChild;
} store[40];
vector<int> ans;
bool process(int root, int currentIndex)
{
  if (currentIndex >= num)
    return false;
  else if (currentIndex == num - 1)
    lastNode = root;
  bool flag = true;
  if (store[root].leftChild != -1)
  {
    int leftIndex = currentIndex * 2 + 1;
    flag = process(store[root].leftChild, leftIndex);
  }
  if (!flag)
    return false;
  if (store[root].rightChild != -1)
  {
    int rightIndex = currentIndex * 2 + 2;
    flag = process(store[root].rightChild, rightIndex);
  }
  return flag;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> num;
  for (size_t i = 0; i < num; i++)
  {
    cin >> tmp;
    if (tmp == "-")
    {
      store[i].leftChild = -1;
    }
    else
    {
      father[charToNumber(tmp)] = i;
      visit[charToNumber(tmp)] = true;
      store[i].leftChild = charToNumber(tmp);
    }
    cin >> tmp;
    if (tmp == "-")
    {
      store[i].rightChild = -1;
    }
    else
    {
      father[charToNumber(tmp)] = i;
      visit[charToNumber(tmp)] = true;
      store[i].rightChild = charToNumber(tmp);
    }
  }
  for (size_t i = 0; i < num; i++)
  {
    if (!visit[i])
      ans.push_back(i);
  }
  if (ans.size() > 1)
  {
    for (auto i : ans)
    {
      if (store[i].leftChild != -1 || store[i].rightChild != -1)
      {
        printf("NO %d", i);
        return 0;
      }
    }
  }
  else
  {
    int root = ans[0];
    bool flag = process(root, 0);
    if (flag)
    {
      printf("YES %d", lastNode);
    }
    else
    {
      printf("NO %d", ans[0]);
    }
  }
  return 0;
}