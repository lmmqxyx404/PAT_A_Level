#include "bits/stdc++.h"
using namespace std;
unordered_map<string, int> alumni;
unordered_map<string, int> guest;
string tmp;
vector<string> stu;
vector<string> gue;

bool older(string asd, string zxc)
{
  auto asd_age = asd.substr(6, 8);
  auto zxc_age = zxc.substr(6, 8);
  return asd_age < zxc_age;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  for (size_t i = 1; i <= n; i++)
  {
    cin >> tmp;
    alumni[tmp] = i;
  }
  cin >> n;
  for (size_t i = 1; i <= n; i++)
  {
    cin >> tmp;
    if (alumni[tmp])
      stu.push_back(tmp);
    else
      gue.push_back(tmp);
  }
  if (stu.empty())
  {
    sort(gue.begin(), gue.end(), older);
    cout << 0 << endl
         << gue[0];
  }
  else
  {
    sort(stu.begin(), stu.end(), older);
    cout << stu.size() << endl
         << stu[0];
  }
  return 0;
}