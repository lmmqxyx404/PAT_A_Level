#include "bits/stdc++.h"
using namespace std;

vector<vector<unsigned short int> > graph;
vector<unsigned short int> ans;
int blockNum, u, v, deepestRoot, n, deepLevel,storeLevel[10024];
bool visit[10024],nodeVisit[10024];

void DFS(int index, int level)
{
  visit[index] = true;
  if (level > deepLevel)
  {
    //storeLevel[index]=level;
    memset(nodeVisit, false, sizeof(nodeVisit));
    deepLevel = level;
    ans.clear();
    ans.push_back(index);
    nodeVisit[index]=true;
  }
  
  else if (level == deepLevel)
  {
    if(!nodeVisit[index]){
      ans.push_back(index);
      nodeVisit[index]=true;
    }
  }
  
  for (int i : graph[index])
  {
    if (!visit[i])
    {
      DFS(i, level + 1);
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  scanf("%d", &n);
  graph.resize(10024);
  /*
  for (unsigned short int i = 0; i < 10010; i++)
  {
    graph[i].resize(10008);
    cout<<graph[i].size()<<endl;
  }
  */
  for (int i = 0; i < n - 1; i++)
  {
    scanf("%d %d", &u, &v);
    graph[(unsigned short int)u].push_back((unsigned short int)v);
    graph[(unsigned short int)v].push_back((unsigned short int)u);
  }
  if (n == 1)
  {
    cout << n;
    return 0;
  }
  for (int i = 1; i <= n; i++)
  {
    if (!visit[i])
    {
      DFS(i, 0);
      blockNum++;
    }
  }
  if (blockNum == 1)
  {
    for (int i = 2; i <= n; i++)
    {
      memset(visit, false, sizeof(visit));
      DFS(i, 0);
    }
    memset(visit, false, sizeof(visit));
    sort(ans.begin(),ans.end());
    // set<int> key(ans.begin(),ans.end());
    /*
    for (int i = 1; i <= n; i++)
    {
      if(storeLevel[i]==deepLevel){
        ans.push_back(i);
      }else if(storeLevel[i]>deepLevel){
        ans.clear();
        deepLevel=storeLevel[i];
        ans.push_back(i);
      }
    }
    */
    for (unsigned short int &i : ans)
    {
      printf("%d\n", i);
      /*
      if(visit[i]) continue;
      else {
        printf("%d\n", i);
        visit[i]=true;
      }
      */
    }
  }
  else
  {
    printf("Error: %d components", blockNum);
  }
  return 0;
}