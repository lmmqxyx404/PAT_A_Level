// 1:14
#include "bits/stdc++.h"
using namespace std;
vector<int> store, ans;
int sp, position[20024], counter_num;
bool visit[20024];
int find_pos(int s)
{
  while (visit[s])
  {
    s++;
  }
  return s;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  int volume, m;
  fill(position, position + 10024, -1);
  cin >> volume >> m;
  for (size_t i = 0; i < m; i++)
  {
    int tmp;
    cin >> tmp;
    if (position[tmp] == -1)
    {
      if (volume == counter_num)
      {
        auto spp = find_pos(sp);
        counter_num--;
        ans.push_back(store[spp]);
        position[store[spp]] = -1;
        visit[spp] = true;
        sp = spp + 1;
      }
      store.push_back(tmp);
      position[tmp] = store.size() - 1;
      counter_num++;
    }
    else
    {
      visit[position[tmp]] = true;
      store.push_back(tmp);
      position[tmp] = store.size() - 1;
    }
  }
  for (size_t i = 0; i < ans.size(); i++)
  {
    printf("%s%d", i ? " " : "", ans[i]);
  }
  return 0;
}