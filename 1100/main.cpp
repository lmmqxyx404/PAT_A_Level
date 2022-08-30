#include "bits/stdc++.h"
using namespace std;
unordered_map<string, int> firstl, secondh;
string num13[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string num14[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int N;
void process(string temp)
{
  string store = "";
  int ans = 0;
  if (temp[0] >= '0' && temp[0] <= '9')
  {
    for (size_t i = 0; temp[i] != '\0'; i++)
    {
      ans = ans * 10 + (int)(temp[i] - '0');
    }
    if (ans / 13)
    {
      cout << num14[ans / 13];
      if (ans % 13)
        cout << ' ';
      else
        return;
    }
    cout << num13[ans % 13];
    return;
  }
  for (size_t i = 0; temp[i] != '\0'; i++)
  {
    if (temp[i] == ' ')
    {
      ans = ans + 13 * secondh[store];
      store = "";
    }
    else
    {
      store = store + temp[i];
    }
  }
  if (secondh[store] % 13)
    ans = secondh[store] * 13;
  else
    ans = ans + firstl[store];
  cout << ans;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  for (size_t i = 1; i < 13; i++)
  {
    firstl.insert({num13[i], i});
    secondh.insert({num14[i], i});
  }
  scanf("%d", &N);
  for (size_t i = 0; i <= N; i++)
  {
    string temp = "";
    getline(cin, temp);
    if (i == 0)       // equal to write the code "cin.get();" to read '\n'
      continue;
    process(temp);
    if (i != N)
      cout << endl;
  }
  return 0;
}