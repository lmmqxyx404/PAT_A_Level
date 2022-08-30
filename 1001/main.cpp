#include "bits/stdc++.h"
using namespace std;
int a, b, total, numLength;
string res, ans;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  //ios::sync_with_stdio(false);
  cin >> a >> b;
  total = a + b;
  if (total < 0)
  {
    cout << '-';
    total *= -1;
  }
  else if (total == 0)
  {
    cout << 0;
    return 0;
  }
  while (total)
  {
    res = char((total % 10 + '0')) + res;
    if (numLength++ % 3 == 2)
      res = ',' + res;
    total /= 10;
  }
  if (numLength % 3==0)
    res.erase(res.begin());
  for (auto i : res)
  {
    cout << i;
  }
  return 0;
}