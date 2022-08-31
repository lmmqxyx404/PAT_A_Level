#include "bits/stdc++.h"
using namespace std;
int k, n, m, set_index;
int graph[1024][1024], father[1024];
set<int> all_caller;
vector<int> suspects, tmp_group, childs[1024];
vector<vector<int>> res;
bool visit[1024];
int get_father(int x)
{
  if (x == father[x])
    return x;
  else
  {
    father[x] = get_father(father[x]);
    return father[x];
  }
}
void merge_set(int x, int y)
{
  int x_fa = get_father(x), y_fa = get_father(y);
  if (x_fa < y_fa)
    father[y_fa] = x_fa;
  else
    father[x_fa] = y_fa;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> k >> n >> m;
  for (size_t i = 1; i <= n; i++)
    father[i] = i;
  for (size_t i = 0; i < m; i++)
  {
    int v, b, val;
    cin >> v >> b >> val;
    graph[v][b] += val;
    all_caller.insert(v);
  }
  for (auto i : all_caller)
  {
    int short_call_num = 0, person = 0;
    for (size_t j = 1; j <= n; j++)
    {
      if (graph[i][j] && graph[i][j] <= 5)
      {
        // cout << i << " " << j << " " << graph[i][j] << endl;
        short_call_num++;
        if (graph[j][i])
          person++;
      }
    }
    if (short_call_num > k && person * 5 <= short_call_num)
      suspects.push_back(i);
  }
  if (suspects.empty())
  {
    cout << "None";
    return 0;
  }
  for (size_t i = 0; i < suspects.size(); i++)
    for (size_t j = i + 1; j < suspects.size(); j++)
      if (graph[suspects[i]][suspects[j]] && graph[suspects[j]][suspects[i]])
        merge_set(suspects[i], suspects[j]);
  /* for (size_t i = 0; i < suspects.size(); i++)
  {
    if (!visit[suspects[i]])
    {
      cout << suspects[i];
      for (size_t j = i + 1; j < suspects.size(); j++)
      {
        if (get_father(suspects[i]) == get_father(suspects[j]))
        {
          cout << " " << suspects[j];
          visit[suspects[j]] = true;
        }
      }
      cout << endl;
    }
  } */

  for (auto i : suspects)
    childs[get_father(i)].push_back(i);
  for (auto i = 1; i <= n; i++)
    if (!childs[i].empty())
      res.push_back(childs[i]);
  for (int i = 0; i < res.size(); i++)
  {
    printf("%s", i ? "\n" : "");
    for (int j = 0; j < res[i].size(); j++)
    {
      printf("%s%d", j ? " " : "", res[i][j]);
    }
  }
  return 0;
}