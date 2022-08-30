#include "bits/stdc++.h"
using namespace std;
int father[10024], N, K, Q, tmp1, tmp2, birdNum = -1;
int queryFather(int x)
{
  //key point: compress the path
  //return x == father[x] ? x : queryFather(father[x]);
  if (x == father[x])
    return x;
  int ancestor = queryFather(father[x]);
  while (x != father[x])
  {
    int tmp = father[x];
    father[x] = ancestor;
    x = tmp;
  }
  return ancestor;
}
unordered_set<int> treeNum;
void unionFather(int qwe, int asd)
{
  int qf = queryFather(qwe);
  int af = queryFather(asd);
  father[qf] = af;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  iota(father, father + 10024, 0);
  scanf("%d", &N);
  for (size_t i = 0; i < N; i++)
  {
    scanf("%d%d", &K, &tmp1);
    birdNum = max(birdNum, tmp1);
    for (int j = 0; j < K - 1; j++)
    {
      scanf("%d", &tmp2);
      birdNum = max(birdNum, tmp2);
      unionFather(tmp1, tmp2);
    }
  }
  for (int i = 1; i <= birdNum; i++)
  {
    int iFather = queryFather(i);
    treeNum.insert(iFather);
  }
  printf("%d %d", treeNum.size(), birdNum);
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++)
  {
    scanf("%d%d", &tmp2, &tmp1);
    if (queryFather(tmp1) == queryFather(tmp2))
    {
      printf("\nYes");
    }
    else
    {
      printf("\nNo");
    }
  }
  return 0;
}
