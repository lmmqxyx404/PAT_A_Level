#include "bits/stdc++.h"
using namespace std;
vector<int> graph[1024];
int maxLevel,nodeNumber,queryNumber;
int res;
struct Node{
  int value,level;
};
bool visit[1024];
void BFS(int index){
  queue<Node> q;
  q.push({index,0});
  while (!q.empty())
  {
    Node current=q.front();
    q.pop();
    visit[current.value]=true;
    if(current.level<maxLevel){
      for (auto i :graph[current.value])
      {
        if(!visit[i]){
          q.push({i,current.level+1});
          visit[i]=true;
          res++;
        }
      }
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
//  ios::sync_with_stdio(false);
  cin>>nodeNumber>>maxLevel;
  for (int i = 1; i <= nodeNumber; i++)
  {
    int tmpCounnter,tmpNumber;
    cin>>tmpCounnter;
    for (size_t j = 0; j < tmpCounnter; j++)
    {
      cin>>tmpNumber;
      graph[tmpNumber].push_back(i);
    }
  }
  cin>>queryNumber;
  while (queryNumber--)
  {
    int tmpNum;
    cin>>tmpNum;
    fill(visit,visit+1021,false);
    res=0;
    BFS(tmpNum);
    cout<<res<<endl;
  }
  return 0;
}