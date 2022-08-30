#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
struct rational
{
  ll numerator, denominator, integer;
} ans, temp, key;
ll get_gcd(ll a, ll s)
{
  return a % s ? get_gcd(s, a % s) : s;
}
void showResult(rational instance)
{
  if (instance.numerator == 0)
  {
    printf("0");
    return;
  }
  if (instance.denominator == 0)
  {
    printf("Inf");
    return;
  }
  bool flag = true;
  if (instance.numerator < 0)
  {
    instance.numerator *= -1;
    flag = false;
  }
  ll gcd = get_gcd(instance.numerator, instance.denominator);
  instance.numerator /= gcd;
  instance.denominator /= gcd;
  instance.integer = instance.numerator / instance.denominator;
  instance.numerator -= instance.denominator * instance.integer;
  if (!flag)
  {
    printf("(-");
    if (instance.integer != 0)
    {
      if (instance.denominator != 1)
      {
        printf("%lld %lld/%lld)", instance.integer, instance.numerator, instance.denominator);
      }
      else
      {
        printf("%lld)", instance.integer);
      }
    }
    else
    {
      printf("%lld/%lld)", instance.numerator, instance.denominator);
    }
  }
  else
  {
    if (instance.integer != 0)
    {
      if (instance.denominator != 1)
      {
        printf("%lld %lld/%lld", instance.integer, instance.numerator, instance.denominator);
      }
      else
      {
        printf("%lld", instance.integer);
      }
    }
    else
    {
      printf("%lld/%lld", instance.numerator, instance.denominator);
    }
  }
}
void add_opt(rational a, rational s)
{
  key.numerator = a.numerator * s.denominator + s.numerator * a.denominator;
  key.denominator = a.denominator * s.denominator;
  showResult(a);
  printf(" + ");
  showResult(s);
  printf(" = ");
  showResult(key);
  printf("\n");
}
void difference_opt(rational a, rational s)
{
  key.numerator = a.numerator * s.denominator - s.numerator * a.denominator;
  key.denominator = a.denominator * s.denominator;
  showResult(a);
  printf(" - ");
  showResult(s);
  printf(" = ");
  showResult(key);
  printf("\n");
}
void product_opt(rational a, rational s)
{
  key.numerator = a.numerator * s.numerator;
  key.denominator = a.denominator * s.denominator;
  showResult(a);
  printf(" * ");
  showResult(s);
  printf(" = ");
  showResult(key);
  printf("\n");
}
void quotient_opt(rational a, rational s)
{
  key.numerator = a.numerator * s.denominator;
  key.denominator = a.denominator * s.numerator;
  if (key.denominator < 0)
  {
    key.denominator *= -1;
    key.numerator *= -1;
  }
  showResult(a);
  printf(" / ");
  showResult(s);
  printf(" = ");
  showResult(key);
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  scanf("%lld/%lld %lld/%lld", &ans.numerator, &ans.denominator, &temp.numerator, &temp.denominator);
  add_opt(ans, temp);
  difference_opt(ans, temp);
  product_opt(ans, temp);
  quotient_opt(ans, temp);
  return 0;
}