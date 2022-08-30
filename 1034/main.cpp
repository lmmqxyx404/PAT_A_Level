#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
// can only accumulate the point weight can not figure out the wdge weight.
unordered_set<int> blockMember;
int n, k, value[1024], counter = 1, uvValue[1024][1024], blockMVP = -1, blockTotal = 0;
vector<vector<int>> graph(1024);
map<string, int> nameToIndex;
string indexToName[1024];
bool visit[1024];

struct Gang
{
  int header, number;
};
vector<Gang> ans;
void stringToInt(string s)
{
  if (nameToIndex[s] == 0)
  {
    nameToIndex[s] = counter;
    indexToName[counter] = s;
    counter++;
  }
}

void DFS(int index)
{
  blockMember.insert(index);
  visit[index] = true;
  for (auto &i : graph[index])
  {
    value[index] += uvValue[index][i];
    value[i] += uvValue[index][i];
    blockTotal += uvValue[index][i];
    if (!visit[i])
    {
      DFS(i);
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  cin >> n >> k;
  for (size_t i = 0; i < n; i++)
  {
    string asd, qwe;
    int tmpVal;
    cin >> asd >> qwe >> tmpVal;
    if(tmpVal<=0||tmpVal>1000)continue;
    stringToInt(asd);
    stringToInt(qwe);
    int u = nameToIndex[asd], v = nameToIndex[qwe];
    cout<<u<<" "<<v<<endl;
    // printf("U is %d,V is %d\n",u,v);
    if (uvValue[u][v] == 0)
    {
      graph[u].push_back(v);
    }
    uvValue[u][v] += tmpVal;
  }
  for (auto i : graph[2])
  {
    printf("i is %d\n",i);
  }
  cout<<endl;
  for (int i = 1; i < counter; i++)
  {
    if (!visit[i])
    {
      DFS(i);
      int tmpHead = -1;
      for (auto j : blockMember)
      {
         printf("value %d is %d\n", j, value[j]);
        if (blockMVP < value[j])
        {
          blockMVP = value[j];
          tmpHead = j;
        }
      }
       printf("block total is %d block head is %d block relative value is %d\n", blockTotal, tmpHead, blockMVP);
      // cout<<"block total is "<<blockTotal<<endl;
      if (blockTotal > k && blockMember.size() > 2)
      {
        ans.push_back({tmpHead, blockMember.size()});
      }
      blockMember.clear();
      blockMVP = -1;
      blockTotal = 0;
    }
  }
  cout << ans.size() << endl;
  for (auto &i : ans)
  {
    printf("%s %d\n", indexToName[i.header].c_str(), i.number);
  }
  return 0;
}

/*
      for (int j = 1; j < counter; j++)
      {
        if (!visit[j])
        {
          printf("%d is %s\n", j, indexToName[j].c_str());
        }
      }
      cout << endl;
*/