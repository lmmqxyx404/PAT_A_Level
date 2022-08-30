#include "bits/stdc++.h"
using namespace std;
const int INF=0x7fffffff;
int G[254][256],n,m,record,annalDis=INF,k,annalIndex,tmpDis;
char ans[3][25]={"TS simple cycle","TS cycle","Not a TS cycle"};
int getRes(){
  int num,head,u,v;
  cin>>num;
  unordered_set<int> store;
  for (size_t i = 1; i <= num; i++)
  {
    cin>>u;
    store.insert(u);
    if(i==1){
      v=u;
      head=u;
      continue;
    }
    if(tmpDis==INF) continue;
    tmpDis=G[u][v]==INF?INF:tmpDis+G[u][v];
    v=u;
  }
  if(head==u&&tmpDis<INF&&store.size()==n){
    return num==n+1?1:2;
  }
  return 3;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  //ios::sync_with_stdio(false);
  cin>>n>>m;
  fill(G[0],G[0]+254*256,INF);
  for (size_t i = 0; i < m; i++)
  {
    int u,v,dis;
    cin>>u>>v>>dis;
    G[u][v]=dis;
    G[v][u]=dis;
  }
  cin>>k;
  for (int i = 1; i <= k; i++)
  {
    tmpDis=0;
    int res=getRes();
    // cout<<"tmpDis = "<<tmpDis<<endl;
    if(res<3&&annalDis>tmpDis){
      annalIndex=i;
      annalDis=tmpDis;
    }
    printf("Path %d: %s (%s)\n",i,tmpDis==INF?"NA":to_string(tmpDis).c_str(),ans[res-1]);
  }
  printf("Shortest Dist(%d) = %d",annalIndex,annalDis);
  return 0;
}