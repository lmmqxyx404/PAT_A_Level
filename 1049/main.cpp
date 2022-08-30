#include "bits/stdc++.h"
using namespace std;
int leftnum, now, rightnum, division = 1, counter, ini;
// 以下两种说法等价
const int max1 = 0x40000000;
const int max2 = 1 << 30;

int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> ini;
  while (rightnum != ini)
  {
    leftnum = ini / division / 10;
    now = ini / division % 10;
    rightnum = ini % division;
    if (now == 1)
    {
      counter += leftnum * division  + rightnum + 1;
    }
    else if (now == 0)
    {
      counter += leftnum * division ;
    }
    else
    {
      counter += (leftnum + 1) * division ;
    }
    division *= 10;
  }
  cout << counter;
  return 0;
}