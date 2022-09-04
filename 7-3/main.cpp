#include "bits/stdc++.h"
using namespace std;

bool graph[1024][1024], visit[1024];
int n, m, k;
bool is_dfs()
{
  memset(visit, false, sizeof(visit));
  vector<int> storev;
  for (size_t j = 0; j < n; j++)
  {
    int tmp;
    cin >> tmp;
    if (visit[tmp])
      return false;
    else
    {
      storev.push_back(tmp);
    }
  }
  for (size_t i = 0; i < storev.size(); i++)
  {
    if (i == 0)
    {
      visit[storev[i]] = true;
      continue;
    }

    if (!graph[storev[i - 1]][storev[i]])
      return false;
  }
  return true;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (size_t i = 0; i < m; i++)
  {
    int uu, vv;
    cin >> uu >> vv;
    graph[uu][vv] = true;
    // graph[vv][uu] = true;
  }
  for (size_t i = 0; i < k; i++)
  {
    printf("%s\n", is_dfs() ? "yes" : "no");
  }
  return 0;
}