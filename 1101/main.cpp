#include "bits/stdc++.h"
using namespace std;

int store[100024], storemax[100024], storemin[100024];
vector<int> ans;
int main()
{
  freopen("../1101/Text.txt", "r", stdin);
  freopen("../1101/Text1.txt", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> store[i];
  }
  storemin[n + 1] = 1e9 + 24;
  storemax[0] = -1;
  for (int i = 1; i <= n; i++)
  {
    storemax[i] = store[i] > storemax[i - 1] ? store[i] : storemax[i - 1];
  }
  for (int i = n; i >= 1; i--)
  {
    if (store[i] < storemin[i + 1])
    {
      storemin[i] = store[i];
    }
    else
    {
      storemin[i] = storemin[i + 1];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (store[i] > storemax[i - 1] && store[i] < storemin[i + 1])
    {
      ans.push_back(store[i]);
    }
  }
  cout << ans.size()<<endl;
  if (ans.size())
  {
    for (int i = 0;; i++)
    {
      cout << ans[i];
      if (i != ans.size() - 1)
      {
        cout << ' ';
      }
      else
      {
        break;
      }
    }
  }
  else{
    cout<<endl;
  }
  return 0;
}