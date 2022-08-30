#include "bits/stdc++.h"
using namespace std;
long long Times, a, b, sum, tmp;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> Times;
  for (int i = 1; i <= (int)Times; i++)
  {
    scanf("%lld%lld%lld",&a,&b,&tmp); //cin >> a >> b >> tmp; error
    sum = a + b;
    if (a > 0 && b > 0 && sum < 0)
    {
      printf("Case #%d: true", i);
    }
    else if (a < 0 && b < 0 && sum >= 0)
    {
      printf("Case #%d: false", i);
    }
    else if (sum > tmp)
    {
      printf("Case #%d: true", i);
    }
    else
    {
      printf("Case #%d: false", i);
    }
    cout<<endl;
  }
  return 0;
}