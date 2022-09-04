#include "bits/stdc++.h"
using namespace std;

int aa[4], bb[4];
bool is_valid(int i)
{
  return i >= 0 && i <= 2;
}
bool validate(int i, int j)
{
  for (int ii = 0; ii < 2; ii++)
  {
    for (int kk = 1; kk <= 2; kk++)
    {
      int tmp = (ii ? 1 : -1) * kk;
      if (is_valid(i + tmp))
      {
        // cout << aa[i + tmp] << " " << aa[i] + tmp << endl;
        if (aa[i + tmp] == ((aa[i] + tmp) % 7))
          return false;
      }
      if (is_valid(j + tmp))
      {
        if (bb[j + tmp] == ((bb[j] + tmp) % 7))
          return false;
      }
    }
  }
  if (i > j)
  {
    return aa[i] == (bb[j] + i - j) % 7;
  }
  else if (i < j)
  {
    return bb[j] == (j - i + aa[i]) % 7;
  }
  else
  {
    return aa[i] == bb[j];
  }
}
char ans[8][20] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char days[3][20] = {"yesterday", "today", "tomorrow"};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  for (size_t i = 0; i < 3; i++)
  {
    cin >> aa[i];
  }
  for (size_t i = 0; i < 3; i++)
  {
    cin >> bb[i];
  }
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++)
    {
      if (validate(i, j))
      {
        if (i == 0)
        {
          printf("%s", ans[(aa[i] + 1) % 7]);
        }
        else if (i == 2)
        {
          printf("%s", ans[aa[i] == 0 ? 6 : aa[i] - 1]);
        }
        else
        {
          printf("%s", ans[aa[i]]);
        }
        printf("\n%s\n%s", days[i], days[j]);
      }
    }
  }

  return 0;
}