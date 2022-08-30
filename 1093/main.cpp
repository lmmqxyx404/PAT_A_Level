#include "bits/stdc++.h"
using namespace std;

char store[100024];
int indexa, p[100024], t[100024], res;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  scanf("%s", store);
  for (size_t i = 0; store[i] != '\0'; i++)
  {
    if (store[i] == 'A')
    {
      indexa++;
    }
    else if (store[i] == 'P')
    {
      p[indexa]++;
    }
    else
    {
      t[indexa]++;
    }
  }
  for (int i = 1; i <= indexa; i++)
  {
    p[i] = p[i] + p[i - 1];
  }
  for (int i = indexa; i > 0; i--)
  {
    t[i] = t[i + 1] + t[i];
  }
  t[0]=t[0]+t[1];
  for (int i = 1; i <= indexa; i++)
  {
    // contemplate the mode computation
    res = ((long long)p[i - 1] * t[i]+res) % 1000000007;
  }
  cout << res;
  return 0;
}