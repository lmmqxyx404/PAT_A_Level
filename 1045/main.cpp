#include "bits/stdc++.h"
using namespace std;
int n, m, l, tmp, store[300], weight, dp[10024], ans = -1;
vector<int> key;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (size_t i = 0; i < m; i++)
  {
    cin >> tmp;
    store[tmp] = ++weight;
  }
  cin >> l;
  for (size_t i = 0; i < l; i++)
  {
    cin >> tmp;
    if (store[tmp])
      key.push_back(tmp);
  }
  for (size_t i = 0; i < key.size(); i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (store[key[i]] >= store[key[j]] && dp[j] + 1 > dp[i])
      {
        dp[i] = dp[j] + 1;
      }
    }
    ans = max(ans, dp[i]);
  }
  printf("%d", ans);
  return 0;
}