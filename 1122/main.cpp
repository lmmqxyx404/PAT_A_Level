#include "bits/stdc++.h"
using namespace std;
bool visit[222][222];
int N,M,K;  //verticle number,edge number,query number
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin>>N>>M;
  for (size_t i = 0; i < M; i++)
  {
    int tmp1,tmp2;
    cin>>tmp2>>tmp1;
    visit[tmp1][tmp2]=visit[tmp2][tmp1]=true;
  }
  cin>>K;
  for (size_t i = 0; i < K; i++)
  {
    int indexNumber,pre,firstIndex,j,aim,flag=1; //verticle number
    /*the above flag is important, it can absorb redundant verticle in this circle */
    unordered_set<int> store; //store the traverse verticle
    cin>>indexNumber>>firstIndex;
    pre=firstIndex;
    store.insert(firstIndex);
    for ( j = 0; j < indexNumber-1; j++)
    {
        cin>>aim;
        store.insert(aim);
        if(visit[pre][aim]) pre=aim;
        else flag=0;
    }
    if(indexNumber==N+1&&store.size()==N&&aim==firstIndex&&flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}