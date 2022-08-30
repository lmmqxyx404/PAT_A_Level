#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

string deal(string input){
  string output="";
  int first=input[0]-'0',counter=1;
  if(input.size()==1){
    return input+"1";
  }
  for (int i = 1; i < input.size(); i++)
  {
    if(input[i]==input[i-1]){
      counter++;
      // first=input[i]-'0';
    }else {
      output=output+(char)(first+'0')+(char)(counter+'0');
      first=input[i]-'0';
      counter=1;
    }
    if(i==input.size()-1){
      output=output+input[input.size()-1]+(char)(counter+'0');
    }
  }
  return output;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  string origin;
  cin>>origin;
  int n;
  cin>>n;
  for (int i = 0; i < n-1; i++)
  {
    origin=deal(origin);
  }
  cout<<origin;
  return 0;
}