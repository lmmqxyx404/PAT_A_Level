
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> n;
  cout << n << "=";
  if (n == 1)
    cout << "1";
  for (size_t i = 2; n != 1; i++)
  {
    ll counter = 0;
    while (n % i == 0)
    {
      counter++;
      n /= i;
    }
    if (counter)
    {
      printf("%d", i);
      if (counter > 1)
        printf("^%d", counter);
      if (n != 1)
        printf("*");
      else
        break;
    }
  }
  return 0;
}