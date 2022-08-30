#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
string asd;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin>>asd;
  int sum=0;
  for (auto i : asd)
  {
    sum+=(int)(i-'0');
  }
  vector<string> ans;
  string spell[11]={"zero","one","two","three","four","five","six","seven","eight","nine"};
  do
  {
    ans.push_back(spell[sum % 10]);
    sum/=10;
  } while (sum);
  for (int i = ans.size()-1; i >=0 ; i--)
  {
    printf("%s%s" ,ans[i].c_str(),i?" ":"\n");
  }
  return 0;
}