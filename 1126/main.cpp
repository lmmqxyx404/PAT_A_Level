#include "bits/stdc++.h"
using namespace std;
vector<int> storeGraph[512];
bool toCompare[512];
int N, M, oddNumber, flag; //verticle number,edge number,odd degree number
void DFS(int root)
{
  queue<int> q;
  q.push(root);
  while (!q.empty())
  {
    int top = q.front();
    q.pop();
    toCompare[top] = true;
    for (auto i : storeGraph[top])
    {
      if (!toCompare[i])
        q.push(i);
    }
  }
}
// contemplate too little;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  //  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    storeGraph[u].push_back(v);
    storeGraph[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
  {
    printf("%d%s", storeGraph[i].size(), i == N ? "\n" : " ");
    if (storeGraph[i].size() & 1)
      oddNumber++;
  }
  DFS(1);
  for (int i = 1; i <= N; i++)
  {
    if (!toCompare[i])
    {
      cout << "Non-Eulerian";
      return 0;
    }
  }
  if (oddNumber == 0)
    cout << "Eulerian";
  else if (oddNumber == 2)
    cout << "Semi-Eulerian";
  else
    cout << "Non-Eulerian";
  return 0;
}