#include "bits/stdc++.h"
using namespace std;
char res[30][30]={};
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  int n1=(s.size()+2)/3;  // pay more attention to the step.
  int n2=s.size()-n1*2+2;
  for (size_t i = 0; i < 30; i++)
  {
    for (size_t j = 0; j < 30; j++)
    {
      res[i][j]=' ';
    }
  }
  for (size_t i = 0; i < n1; i++)
  {
    res[i][0]=s[i];
    res[i][n2-1]=s[s.size()-1-i];
  }
  for (size_t i = 0; i < n2; i++)
  {
    res[n1-1][i]=s[n1-1+i];
  }
  for (size_t i = 0; i < n1; i++)
  {
    for (size_t j = 0; j < n2; j++)
    {
      cout<<res[i][j];
    }
    cout<<endl;
  }
  return 0;
}