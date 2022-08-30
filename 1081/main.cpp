#include "bits/stdc++.h"
using namespace std;

struct rational
{
  long long numerator, denominator;
} ans, temp;
int num;
long long get_gcd(long long a, long long b)
{
  return a % b ? get_gcd(b, a % b) : b;
}
rational add_operation(rational a, rational s)
{
  if (a.numerator == 0)
    return s;
  if (s.numerator == 0)
    return a;
  long long gcd = get_gcd(a.denominator, s.denominator);
  rational key;
  key.denominator = a.denominator / gcd * s.denominator;
  key.numerator = a.numerator * (s.denominator / gcd) + s.numerator * (a.denominator / gcd);
  // printf("计算结果：%lld/%lld\n", key.numerator, key.denominator);  // debug
  return key;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> num;
  for (size_t i = 0; i < num; i++)
  {
    scanf("%lld/%lld", &temp.numerator, &temp.denominator);
    // cout << temp.numerator << "<----" << temp.denominator << "<-----" << endl;  //调试
    ans = add_operation(ans, temp);
  }
  bool flag = true;
  if (ans.numerator < 0)
  {
    ans.numerator *= -1;
    flag = false;
  }
  long long integer, gcdans;
  integer = ans.numerator / ans.denominator;
  ans.numerator = ans.numerator - ans.denominator * integer;
  if (ans.numerator == 0)
  {
    printf("%lld", integer);
    return 0;
  }
  gcdans = get_gcd(ans.numerator, ans.denominator);
  ans.numerator /= gcdans;
  ans.denominator /= gcdans;
  if (!flag)
  {
    integer *= -1;
    ans.numerator *= -1;
  }
  if (integer != 0)
  {
    printf("%lld ", integer);
  }
  printf("%lld/%lld", ans.numerator, ans.denominator);
  return 0;
}