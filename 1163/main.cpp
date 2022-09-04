#include "bits/stdc++.h"
using namespace std;

int graph[1024][1024], nv, ne, k, tmp[1024], dis[1024];
bool is_dijkstra(int sp)
{
  fill(dis, dis + 1024, INT_MAX);
  bool visit[1024] = {false};
  fill(visit, visit + 1024, false);
  dis[sp] = 0;
  for (int i = 0; i < nv; i++)
  {
    int tmpv = -1, mindis = INT_MAX;
    for (int j = 1; j <= nv; j++)
    {
      if (!visit[j] && dis[j] < mindis)
      {
        mindis = dis[j];
        tmpv = j;
      }
    }
    if (dis[tmpv] != dis[tmp[i]] || tmpv == -1)
      return false;
    visit[tmpv] = true;
    for (int k = 1; k <= nv; k++)
    {
      if (graph[tmpv][k] < INT_MAX && dis[k] > dis[tmpv] + graph[tmpv][k])
      {
        dis[k] = dis[tmpv] + graph[tmpv][k];
        // cout << "dis " << k << " is： " << dis[k];
      }
      // cout << endl;
    }
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
  fill(graph[0], graph[0] + 1024*1024, INT_MAX);
  cin >> nv >> ne;
  for (int i = 0; i < ne; i++)
  {
    int u, v;
    cin >> u >> v;
    cin >> graph[u][v];
    graph[v][u] = graph[u][v];
  }
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    memset(tmp, 0, sizeof(tmp));
    for (int j = 0; j < nv; j++)
    {
      cin >> tmp[j];
    }
    printf("%s\n", is_dijkstra(tmp[0]) ? "Yes" : "No");
  }
  return 0;
}