// 20:07
#include "bits/stdc++.h"
using namespace std;
int n;
bool visit[22];
struct node
{
  string val;
  int lchild, rchild;

} nodes[22];

string postorder(int root)
{
  if (root == -1)
    return "";
  if (nodes[root].lchild == -1 && nodes[root].rchild != -1)
  {
    return "(" + nodes[root].val + postorder(nodes[root].rchild) + ")";
  }
  else
  {
    return "(" + postorder(nodes[root].lchild) + postorder(nodes[root].rchild) + nodes[root].val + ")";
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> nodes[i].val >> nodes[i].lchild >> nodes[i].rchild;
    if (nodes[i].lchild != -1)
    {
      visit[nodes[i].lchild] = true;
    }
    if (nodes[i].rchild != -1)
    {
      visit[nodes[i].rchild] = true;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (!visit[i])
    {
      cout << postorder(i);
      break;
    }
  }
  return 0;
}