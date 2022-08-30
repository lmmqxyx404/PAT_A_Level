#include "bits/stdc++.h"
using namespace std;
set<int, greater<int>> store;
double ans[1024];
int k;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  for (int i = 0; i < 2; i++)
  {
    cin >> k;
    for (size_t j = 0; j < k; j++)
    {
      int exp;
      double coe;
      cin >> exp >> coe;
      ans[exp] += coe;
      store.insert(exp);
      if (ans[exp] == 0.0)                /*   these are key codes  */
        store.erase(exp);      
    }
  }
  //reverse(store.begin(),store.end());
  cout << store.size();
  for (auto i : store)
  {
    //cout<<" i = "<<i<<endl;
    if (ans[i] != 0.0)
      printf(" %d %.1f", i, ans[i]);
  }
  return 0;
}