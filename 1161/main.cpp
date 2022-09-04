#include "bits/stdc++.h"
using namespace std;

struct node
{
  string val, next;
};
struct fullnode
{
  string addr, val, next;
};

vector<fullnode> full1, full2, res;
string add1, add2;
int n;
unordered_map<string, node> mp;
bool flag1, flag2;

void initialize(string &sp, vector<fullnode> &resss)
{
  while (sp != "-1")
  {
    fullnode tmp{sp, mp[sp].val, mp[sp].next};
    resss.push_back(tmp);
    sp = mp[sp].next;
  }
}

void merge(vector<fullnode> &long_list, vector<fullnode> &shortlist)
{
  int llen = long_list.size(), slen = shortlist.size(), counterll = 0, counterss = 0;
  while (counterll < llen || counterss < slen)
  {
    for (int i = 0; i < 2 && counterll < llen; i++)
    {
      // printf("%s\n%s %s ", counterll ? long_list[counterll].addr.c_str() : "", long_list[counterll].addr.c_str(), long_list[counterll++].val.c_str());
      if (counterll == 0)
      {
        cout << long_list[counterll].addr << " " << long_list[counterll].val << " ";
      }
      else
      {
        cout << long_list[counterll].addr << "\n"
             << long_list[counterll].addr << " " << long_list[counterll].val << " ";
      }
      // cout << (counterll ? long_list[counterll].addr + "\n" : "") << long_list[counterll].addr << long_list[counterll].val;
      counterll++;
      // res.push_back(long_list[counterll++]);
    }
    if (counterss < slen)
    {
      cout << shortlist[slen - counterss - 1].addr << "\n"
           << shortlist[slen - counterss - 1].addr << " " << shortlist[slen - counterss - 1].val << " ";
      counterss++;
      // printf("%s\n%s %s ", shortlist[slen - counterss].addr.c_str(), shortlist[slen - counterss].addr.c_str(), shortlist[slen - ++counterss].val.c_str());
      // res.push_back(shortlist[slen - ++counterss]);
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> add1 >> add2 >> n;
  vector<node> ll1, ll2;
  for (size_t i = 0; i < n; i++)
  {
    string tmpadd;
    node tmpnode;
    cin >> tmpadd >> tmpnode.val >> tmpnode.next;
    mp[tmpadd] = tmpnode;
  }
  initialize(add1, full1);
  initialize(add2, full2);
  if (full1.size() < full2.size())
    merge(full2, full1);
  else
    merge(full1, full2);
  printf("-1");
  for (size_t i = 0; i < res.size(); i++)
    printf("%s %s %s\n", res[i].addr.c_str(), res[i].val.c_str(), i == res.size() - 1 ? "-1" : res[i + 1].addr.c_str());
  return 0;
}