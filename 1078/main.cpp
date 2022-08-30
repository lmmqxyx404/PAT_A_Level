#include "bits/stdc++.h"
using namespace std;
int prime[20024], counterPrime, msize, n;
bool visit[20024], visitTable[20024];
void getPrimeList()
{
  fill(visit + 2, visit + 20023, true);
  for (size_t i = 2; i < 20001; i++)
  {
    if (visit[i])
    {
      prime[counterPrime++] = i;
    }
    for (size_t j = 0; j < counterPrime; j++)
    {
      int tmp = prime[j] * i;
      if (tmp > 20000)
        break;
      visit[tmp] = false;
    }
  }
}
int getminPrime(int a)
{
  for (size_t i = 0; i < counterPrime; i++)
  {
    if (prime[i] > a)
      return prime[i];
  }
}
// 注意题目隐含条件，msize计算出来的值可以大于10e4.
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  getPrimeList();
  cin >> msize >> n;
  if (!visit[msize])
    msize = getminPrime(msize);
  for (size_t i = 0; i < n; i++)
  {
    int tmp, flag = -1;
    cin >> tmp;
    for (size_t j = 0; j < msize; j++)
    {
      if (!visitTable[(tmp + j * j) % msize])
      {
        flag = (tmp + j * j) % msize;
        visitTable[(tmp + j * j) % msize] = true;
        break;
      }
    }
    if (flag == -1)
      cout << "-";
    else
    {
      cout << flag;
    }
    if (i != n - 1)
      cout << " ";
  }
  return 0;
}