#include "bits/stdc++.h"
using namespace std;
const int INF = 0x7fffffff;
int lineNumber, stationNumber, startPoint, endPoint, searchStartPopint, searchEndPoint; //地铁线路数量,每条线路的站点数目,起点与终点，查询时的起点与终点
unordered_map<int, int> edgeToLine;                                                     // startPoint*10000+endPoint,lineNumber
vector<int> graph[10024], cachedPath[10024], resultPath,finalResultPath;
int queryNumber, answer, dis[10027];
int transferNumber;
vector<pair<int,int> >transfer;

void DFS(int endP){
  resultPath.push_back(endP);
  if(endP==searchStartPopint){
    reverse(resultPath.begin(),resultPath.end());
    int tmpTransferNumber=0;
    vector<pair<int,int> >tmpTransfer;
    tmpTransfer.push_back({resultPath[0],-1});
    for (size_t i = 0; i < resultPath.size()-2; i++)
    {
      int firstLine=edgeToLine[resultPath[i]*10000+resultPath[i+1]];
      int secondLine=edgeToLine[resultPath[i+1]*10000+resultPath[i+2]];
      if(firstLine!=secondLine){
        tmpTransferNumber++;
        tmpTransfer.push_back({resultPath[i+1],firstLine});
      }
    }
    if(tmpTransferNumber<transferNumber){
      transferNumber=tmpTransferNumber;
      transfer=tmpTransfer;
      finalResultPath=resultPath;
    }
    reverse(resultPath.begin(),resultPath.end());
  }
  for (auto i :cachedPath[endP])
  {
    DFS(i);
  }
  resultPath.pop_back();
}
void BFS(int start)
{
  for (size_t i = 0; i < 10021; i++)
  {
    cachedPath[i].clear();
    dis[i] = INF;
  }
  queue<int> q; // 从源点开始遍历
  q.push(start);
  dis[start] = 0;
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    if (dis[current] > dis[searchEndPoint])
    {
      continue;
    }
    for (auto i : graph[current])
    {
      if (dis[i] >= dis[current] + 1)
      {
        if (dis[i] == INF)  // 可以判断是否需要加入遍历的队列
        {
          q.push(i);
        }
        if(dis[i]>dis[current]+1){
          cachedPath[i].clear();
        }
        cachedPath[i].push_back(current);
        dis[i]=dis[current]+1;
      }
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  cin >> lineNumber;
  for (size_t i = 1; i <= lineNumber; i++)
  {
    cin >> stationNumber >> startPoint;
    for (size_t j = 1; j < stationNumber; j++, startPoint = endPoint)
    {
      cin >> endPoint;
      graph[startPoint].push_back(endPoint);
      graph[endPoint].push_back(startPoint);
      edgeToLine.insert({startPoint * 10000 + endPoint, i});
      edgeToLine.insert({endPoint * 10000 + startPoint, i});
    }
  }
  cin >> queryNumber;
  while (queryNumber--)
  {
    cin >> searchStartPopint >> searchEndPoint;
    transferNumber=INF;
    transfer.clear();
    BFS(searchStartPopint);
    resultPath.clear();
    cout<<dis[searchEndPoint]<<endl;
    DFS(searchEndPoint);
    if(transferNumber==0){
      printf("Take Line#%d from %04d to %04d.\n",edgeToLine[finalResultPath[finalResultPath.size()-2]*10000+finalResultPath[finalResultPath.size()-1]],finalResultPath[0],finalResultPath[finalResultPath.size()-1]);  
      continue;
    }
    int i = 1;
    for ( ; i < transfer.size(); i++)
    {
      printf("Take Line#%d from %04d to %04d.\n",transfer[i].second,transfer[i-1].first,transfer[i].first);
    }
    printf("Take Line#%d from %04d to %04d.\n",edgeToLine[finalResultPath[finalResultPath.size()-2]*10000+finalResultPath[finalResultPath.size()-1]],transfer[i-1].first,finalResultPath[finalResultPath.size()-1]);
  }
  return 0;
}