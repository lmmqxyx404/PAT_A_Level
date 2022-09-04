#include "bits/stdc++.h"
using namespace std;

int n, num[1024];
vector<int> store;
bool max_heap = true, min_heap = true;
void dfs(int root = 1)
{
  store.push_back(num[root]);
  if (root * 2 <= n)
  {
    if (root * 2 + 1 <= n)
      dfs(root * 2 + 1);
    dfs(root * 2);
  }
  else
  {
    for (size_t i = 0; i < store.size(); i++)
    {
      if (i)
      {
        max_heap = max_heap ? store[i] < store[i - 1] : max_heap;
        min_heap = min_heap ? store[i] > store[i - 1] : min_heap;
      }
      printf("%s%d", i ? " " : "", store[i]);
    }
    cout << endl;
  }
  store.pop_back();
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> n;
  for (size_t i = 1; i <= n; i++)
  {
    cin >> num[i];
  }
  dfs();
  if (max_heap)
  {
    cout << "Max Heap";
  }
  else if (min_heap)
  {
    cout << "Min Heap";
  }
  else
  {
    cout << "Not Heap";
  }

  return 0;
}