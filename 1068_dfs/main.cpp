#include "bits/stdc++.h"
using namespace std;

int n, m, store[10024];
bool flag, jump_loop;
vector<int> values;
void dfs(int index, int total)
{
  /* for (auto i : values)
  {
    printf("%d ", i);
  }
  printf("index:%d  total:%d\n", index, total); */
  /* if (flag || index >= n)
  {
    return;
  }
  if (total < 0)
  {
    return;
  }
  else if (total == 0)
  {
    flag = true;
    return;
  }
  if (store[index] > total)
  {
    return;
  } */
  if (total < 0)
    return;
  else if (total == 0)
  {
    flag = true;
    for (size_t i = 0; i < values.size(); i++)
    {
      printf("%s%d", i ? " " : "", values[i]);
    }
    return;
  }
  for (int i = index; i < n; i++)
  {
    if (store[i] > total)
      return;
    values.push_back(store[i]);
    dfs(i + 1, total - store[i]);
    if (flag)
      return;
    values.pop_back();
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> n >> m;
  int res;
  for (size_t i = 0; i < n; i++)
  {
    scanf("%d", &store[i]);
    res += store[i];
  }
  // pay attention to the worst case.
  if (res < 0 || res < m)
  {
    printf("No Solution");
    return 0;
  }
  sort(store, store + n);
  dfs(0, m);
  if (!flag)
    printf("No Solution");
  return 0;
}