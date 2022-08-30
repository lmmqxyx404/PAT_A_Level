#include "bits/stdc++.h"
using namespace std;
vector<int> storeId[40], storeWeight;
int indexa, tmp, rankl = 1, np, ng, i, j, storeRank[10024];
bool visit[100024];

struct cmp
{
  bool operator()(int &a, int &s)
  {
    return storeWeight[a] < storeWeight[s];
  }
};
priority_queue<int, vector<int>, cmp> race, nill;

int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> np >> ng;
  for (size_t i = 0; i < np; i++)
  {
    cin >> tmp;
    storeWeight.push_back(tmp);
  }
  for (size_t i = 0; i < np; i++)
  {
    cin >> tmp;
    storeId[0].push_back(tmp);
  }
  do
  {
    for (i = 0; i < storeId[indexa].size();)
    {
      for (j = 0; j < ng && j + i < storeId[indexa].size(); j++)
      {
        race.push(storeId[indexa][j + i]);
      }
      i = j + i;
      if (!race.empty())
      {
        storeId[indexa + 1].push_back(race.top());
        race = nill;
      }
    }
    indexa += 1;
  } while (storeId[indexa].size() > 1);
  for (i = indexa; i >= 0; i--)
  {
    int validIndex = 0;
    for (j = 0; j < storeId[i].size(); j++)
    {
      int tmp2 = storeId[i][j];
      if (!visit[tmp2])
      {
        visit[tmp2] = true;
        storeRank[tmp2] = rankl;
        validIndex++;
      }
    }
    rankl = rankl + validIndex;
  }
  for (i = 0; i < np; i++)
  {
    printf("%d%s", storeRank[i], i == np - 1 ? "" : " ");
  }
  return 0;
}