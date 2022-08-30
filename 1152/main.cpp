#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

bool check(int s){
 if(s<2){
   return false;
 }
 if(s!=2&&s%2==0) return false;
 for (int i = 3; i*i <=s ; i++)
 {
   if(s%i==0) return false;
 }
 return true;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  string lstr,testStr;
  int l,k;
  cin>>l>>k>>lstr;
  for (int i = 0; i <= l-k; i++)
  {
    testStr=lstr.substr(i,k);
    // cout<<stoi(testStr)<<endl;
    if(check(stoi(testStr))){
      cout<<testStr;
      return 0;
    }
  }
  cout<<"404";
  return 0;
}