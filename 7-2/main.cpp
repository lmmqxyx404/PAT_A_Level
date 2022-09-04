#include "bits/stdc++.h"
using namespace std;

vector<int> store;
vector<int> ans;
bool visit[10024];
int position[10024];

int find_pos(int num)
{
  for (int i = 0; i < store.size(); i++)
  {
  }
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
  for (int i = 1; i <= m; i++)
  {
    int tmp;
    cin >> tmp;
    if (position[tmp] == -1)
    {
      if (store.size() == volume)
      {
        ans.push_back(store.front());
        position[store.front()] = -1;
        store.erase(store.begin());
      }
      store.push_back(tmp);
      position[tmp] = store.size() - 1;
    }
    else
    {
      store.erase(find(store.begin(), store.end(), tmp));
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