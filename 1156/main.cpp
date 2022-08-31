#include "bits/stdc++.h"
using namespace std;

bool is_prime(int x)
{
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; i++)
    if (!(x % i))
      return false;
  return true;
}
void sexy_num(int x)
{
  if (is_prime(x) && (is_prime(x - 6) || is_prime(x + 6)))
    printf("Yes\n%d", is_prime(x - 6) ? x - 6 : x + 6);
  x = x & 1 ? x : x + 1;
  while (true)
  {
    if (is_prime(x) && (is_prime(x - 6) || is_prime(x + 6)))
    {
      printf("No\n%d", x);
      break;
    }
    x += 2;
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  int x;
  cin >> x;
  sexy_num(x);
  return 0;
}