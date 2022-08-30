#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
string initial;
ll count_num;
bool judge(string s)
{
  string asd(s);
  reverse(s.begin(), s.end());
  return asd == s;
}
string rev(string s)
{
  string a(s), ans = "";
  reverse(s.begin(), s.end());
  int pre = 0, res;
  for (int i = a.length() - 1; i >= 0; i--)
  {
    res = (int)(a[i] - '0') + (int)(s[i] - '0') + pre;
    ans = (char)(res % 10 + '0') + ans;
    pre = res / 10;
  }
  return pre?'1'+ans:ans;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> initial >> count_num;
  for (size_t i = 0; i < count_num; i++)
  {
    if (judge(initial))
    {
      cout << initial << '\n'
           << i;
      return 0;
    }
    else
    {
      initial = rev(initial);
    }
  }
  cout << initial << '\n'
       << count_num;
  return 0;
}