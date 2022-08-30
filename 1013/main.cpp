#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

vector<int> graph[1024];
bool visit[1024];
int n,m,k;

// st means start point
void DFS(int sp,int ignorePoint){
  for (auto &i: graph[sp] )
  {
    if(!visit[i]&&i!=ignorePoint){
      visit[i]=true;
      DFS(i,ignorePoint);
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin>>n>>m>>k;
  for (size_t i = 0; i < m; i++)
  {
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (size_t i = 0; i < k; i++)
  {
    int ignoreVetex,block=0; // block-1 is the answer
    cin>>ignoreVetex;
    fill(visit,visit+1023,false);
    for (int i = 1; i <= n; i++)
    {
      if(!visit[i]&&i!=ignoreVetex){
        DFS(i,ignoreVetex);
        block++;
      }
    }
    cout<<block-1<<endl;
  }
  return 0;
}