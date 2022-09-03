#include "bits/stdc++.h"
using namespace std;

bool graph[222][222], visit[222];
vector<int> pre[222];
int n, m, k, l;
bool need_help(vector<int> &per)
{
  for (auto i = 0; i < per.size(); i++)
  {
    for (auto j = i + 1; j < per.size(); j++)
    {
      if (!graph[per[i]][per[j]])
        return true;
    }
  }
  return false;
}
int find_common(set<int> &friendsss, vector<int> &area_person)
{
  for (auto i : friendsss)
  {
    bool flag = true;
    for (auto j : area_person)
    {
      if (!graph[i][j])
      {
        flag = false;
        break;
      }
    }
    if (flag)
      return i;
  }
  return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (size_t i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u][v] = true;
    graph[v][u] = true;
    pre[u].push_back(v);
    pre[v].push_back(u);
  }
  cin >> k;
  for (size_t i = 1; i <= k; i++)
  {
    cin >> l;
    vector<int> area_p;
    memset(visit, false, 1 * (n + 1));
    for (size_t j = 0; j < l; j++)
    {
      int person;
      cin >> person;
      area_p.push_back(person);
      visit[person] = true;
    }
    if (need_help(area_p))
    {
      printf("Area %d needs help.\n", i);
    }
    else
    {
      set<int> friends;
      for (auto ii : area_p)
      {
        for (auto jj : pre[ii])
        {
          if (!visit[jj])
          {
            visit[jj] = true;
            friends.insert(jj);
          }
        }
      }
      int find_res = find_common(friends, area_p);
      if (find_res == -1)
      {
        printf("Area %d is OK.\n", i);
      }
      else
      {
        printf("Area %d may invite more people, such as %d.\n", i, find_res);
      }
    }
  }

  return 0;
}