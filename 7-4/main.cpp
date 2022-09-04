#include "bits/stdc++.h"
using namespace std;

struct node
{
  int val;
  int next[6];
} nodes[51];
int n, d, k, pre_arr[1024];
int buildtree(int prel, int prer)
{
  if (prel > prer)
  {
    return -1;
  }
  node root;
  root.val = pre_arr[prel];
  for (int i = 0; i < d; i++)
  {
    if (i == 0)
    {
      root.next[i] = buildtree(prel + 1);
    }
  }

  return prel;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> n >> d;
  return 0;
}