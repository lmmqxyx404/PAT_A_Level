#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll temp, radix;
ll Reverse(ll a, ll radix)
{
  vector<ll> res;
  while (a)
  {
    res.push_back(a % radix);
    a /= radix;
  }
  ll key = 0;
  for (auto i : res)
  {
    key = key * radix + i;
  }
  return key;
}
bool judge(ll a)
{
  // watch out the range of a([0,inf])
  if (a < 2)
    return false;
  if (a == 2 || a == 3)
    return true;
  for (ll i = 2; i * i < a + 0.1; i++)
  {
    if (a % i == 0)
      return false;
  }
  return true;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  while (temp >= 0)
  {
    scanf("%lld", &temp);
    if (temp < 0)
      break;
    scanf("%lld", &radix);
    if (!judge(temp))
    {
      printf("No\n");
      continue;
    }
    temp = Reverse(temp, radix);
    if (judge(temp))
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
  return 0;
}