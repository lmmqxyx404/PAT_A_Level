#include "bits/stdc++.h"
using namespace std;
const int inf = 0x7fffffff;
vector<int> store[512], answerPath[512], tmppath;
int dis[512][512], pathNumber;
double value[512],maxTeam = -1;
int n, m, sp, ep;
bool visit[512];
void solve(int sp)
{
  int tmpdis[512];
  fill(tmpdis, tmpdis + 512, inf);
  tmpdis[sp] = 0;
  for (int j = 0; j < n; j++)
  {
    int mindis = inf, index = -1;
    for (int i = 0; i < n; i++)
    {
      if (!visit[i] && tmpdis[i < mindis])
      {
        mindis = tmpdis[i];
        index = i;
      }
    }
    if (index == -1)
      return;
    visit[index] = true;
    for (auto i : store[index])
    {
      if (tmpdis[i] > tmpdis[index] + dis[index][i])
      {
        tmpdis[i] = tmpdis[index] + dis[index][i];
        answerPath[i].clear();
        answerPath[i].push_back(index);
      }
      else if (tmpdis[i] == tmpdis[index] + dis[index][i])
      {
        answerPath[i].push_back(index);
      }
    }
  }
}
void DFS(int cp)
{
  tmppath.push_back(cp);
  if (cp == sp)
  {
    pathNumber++;
    double tmpTeam = 0;
    for (auto i : tmppath)
    {
      tmpTeam += value[i];
    }
    maxTeam = max(maxTeam, tmpTeam);
    tmppath.pop_back();
    return;
  }
  for (auto i : answerPath[cp])
  {
    DFS(i);
  }
  tmppath.pop_back();
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> n >> m >> sp >> ep;
  for (size_t i = 0; i < n; i++)
  {
    cin >> value[i];
  }
  for (size_t i = 0; i < m; i++)
  {
    int lp, rp;
    cin >> lp >> rp;
    cin >> dis[lp][rp];
    dis[rp][lp] = dis[lp][rp];
    store[lp].push_back(rp);
    store[rp].push_back(lp);
  }
  solve(sp);
  DFS(ep);
  printf("%d %.0lf",pathNumber,maxTeam);
  return 0;
}