#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

int weight[10024], amount, num;
bool dp[10001][102], isSelected[10001][102]; // The former i goods weight to j.

int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  //ios::sync_with_stdio(false);
  cin >> num >> amount;
  for (int i = 1; i <= num; i++)
  {
    cin >> weight[i];
  }
  sort(weight + 1, weight + num + 1, [](int a, int b) { return a > b; });
  dp[0][0] = true;
  for (int i = 1; i <= num; i++)
  {
    for (int j = 0; j <= amount; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= weight[i])
      {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - weight[i]];
        if (dp[i - 1][j - weight[i]])
        {
          isSelected[i][j] = true;
        }
      }
    }
  }
  if (dp[num][amount])
  {
    bool outputFormat = false;
    for (int i = num; i > 0; i--)
    {
      if (isSelected[i][amount])
      {
        printf("%s%d", outputFormat ? " " : "", weight[i]);
        amount -= weight[i];
        outputFormat = true;
      }
    }
    cout << endl;
  }
  else
  {
    cout << "No Solution";
  }
  return 0;
}
/*
for (int i = 1; i <= num; i++)
{
  for (int j = 0; j <= amount; j++)
  {
    printf("isSelected[%d][%d] %s  ", i, j, isSelected[i][j] ? "true " : "false");
  }
  cout << endl;
}
*/