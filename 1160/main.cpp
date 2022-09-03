// 10:45
#include "bits/stdc++.h"
using namespace std;
int N, K, M, res_num;
vector<int> store;

struct node
{
  int digit_value, value;
};
vector<node> node_store;
int gcd(int x, int y)
{
  return y ? gcd(y, x % y) : x;
}

int get_digit_sum(int x)
{
  return x ? x % 10 + get_digit_sum(x / 10) : 0;
}

bool is_prime(int x)
{
  if (x <= 2)
    return false;
  if (x % 2)
  {
    for (int i = 3; i * i < x; i += 2)
      if (x % i == 0)
        return false;
    return true;
  }
  else
    return false;
}
void dfs(int accumulate = 0)
{
  for (int i = 0; i < 10; i++)
  {
    if (store.empty() && i == 0)
      continue;
    else
    {
      store.push_back(i);
      if ((K - store.size()) * 9 < M - accumulate - i)
      {
        store.pop_back();
        continue;
      }
      if (store.size() == K && accumulate + i == M)
      {

        int tmp_num_1 = 0;
        for (auto i : store)
          tmp_num_1 = tmp_num_1 * 10 + i;
        int digit_sum = get_digit_sum(tmp_num_1 + 1);
        int gcd_num = gcd(digit_sum, M);
        if (is_prime(gcd_num))
        {
          res_num++;
          node tmp{digit_sum, tmp_num_1};
          node_store.push_back(tmp);
          //printf("%d %d\n", digit_sum, tmp_num_1);
        }
      }
      else
      {
        dfs(accumulate + i);
      }
      store.pop_back();
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> N;
  for (size_t i = 1; i <= N; i++)
  {
    cin >> K >> M;
    res_num = 0;
    node_store.clear();
    printf("Case %d\n", i);
    dfs();
    if (res_num)
    {
      sort(node_store.begin(), node_store.end(), [](node a, node b)
           { return a.digit_value == b.digit_value ? a.value < b.value : a.digit_value < b.digit_value; });
      for (auto ii : node_store)
        printf("%d %d\n", ii.digit_value, ii.value);
    }
    else
    {
      cout << "No Solution" << endl;
    }
  }
  return 0;
}