#include "bits/stdc++.h"
using namespace std;
unordered_map<string, int> store;
int m, n, maxn = -1;
string s, ans;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> m >> n;
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      cin >> s;
      store[s]++;
    }
  }
  for (auto i : store)
  {
    if (i.second > maxn)
    {
      maxn = i.second;
      ans = i.first;
    }
  }
  cout<<ans;
  return 0;
}