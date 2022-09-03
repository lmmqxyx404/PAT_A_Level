#include "bits/stdc++.h"
using namespace std;

vector<string> store[30], res;
string words;
int ll, num;
bool new_words;
void shuchu(string str)
{
  for (size_t i = 0; i < 7; i++)
  {
    for (size_t j = 0; j < str.size(); j++)
    {
      printf("%s", j ? " " : "");
      cout << store[str[j] - 'A'][i];
    }
    cout << endl;
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  for (size_t i = 0; i < 26; i++)
  {
    for (size_t j = 0; j < 7; j++)
    {
      string tmp;
      getline(cin, tmp);
      store[i].push_back(tmp);
    }
  }
  getline(cin, words);
  words = words + ".";
  for (size_t i = 0; i < words.length(); i++)
  {
    if (words[i] >= 'A' && words[i] <= 'Z')
    {
      if (!new_words)
      {
        ll = i;
        new_words = true;
      }
    }
    else
    {
      if (new_words)
      {
        new_words = false;
        auto tmpstr = words.substr(ll, i - ll);
        printf("%s", num ? "\n" : "");
        num++;
        shuchu(tmpstr);
      }
    }
  }
  return 0;
}