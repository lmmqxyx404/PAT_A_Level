#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int long INF = 20000;
ll n;
vector<ll> prime;
bool visit[20048];
struct factor
{
  ll coefficient, exponent;
};
vector<factor> ans;
void getPrimeVector()
{
  for (ll i = 2; i < INF; i++)
  {
    if (!visit[i])
    {
      visit[i] = true;
      prime.push_back(i);
    }
    for (size_t j = 0; j < prime.size(); j++)
    {
      ll tmp = i * prime[j];
      if (tmp > INF)
        break;
      visit[tmp] = true;
    }
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  getPrimeVector();
  int index = 0;
  // for (auto i : prime)
  // {
  //   cout << i << "\t";
  //   index++;
  //   if (index % 10 == 0)
  //     cout << endl;
  //   if (index % 1000 == 0)
  //     break;
  // }

  cin >> n;
  cout << n << "=";
  if (n == 1)
    cout << "1";
  for (size_t i = 0; n != 1; i++)
  {
    ll counter = 0;
    while (n % prime[i] == 0)
    {
      counter++;
      n /= prime[i];
    }
    if (counter)
      ans.push_back({prime[i], counter});
  }
  for (size_t i = 0; i < ans.size(); i++)
  {
    cout << ans[i].coefficient;
    if (ans[i].exponent > 1)
      cout << "^" << ans[i].exponent;
    if (i != ans.size() - 1)
      cout << "*";
  }
  return 0;
}
