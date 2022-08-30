#include "bits/stdc++.h"
using namespace std;
unordered_map<string, int> ans;
string store, tmp, key;
int maxn = -1;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  getline(cin, store);
  for (int i = 0; i < store.length(); i++)
  {
    if (isalnum(store[i]))
    {
      store[i] = tolower(store[i]);
      tmp += store[i];
    }
    else if (!tmp.empty())
    {
      ans[tmp]++;
      tmp.clear();
    }
  }
  if (!tmp.empty())
    ans[tmp]++;
  for (auto i : ans)
  {
    if (i.second > maxn)
    {
      key = i.first;
      maxn = i.second;
    }
    else if (i.second == maxn && i.first < key)
    {
      key = i.first;
    }
  }
  printf("%s %d", key.c_str(), ans[key]);
  return 0;
}