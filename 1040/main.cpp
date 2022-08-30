#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
int ans=1,len,dp[1024][1024];
string store;

/*
This is a dynamic plan solution
And for this question, you can try to use force algorithm
*/
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  getline(cin,store);
  //cin>>store;
  
  len=store.length();
  for (int i = 0; i < len; i++)
  {
    dp[i][i]=1;
    if(i<len-1){
      if(store[i]==store[i+1]){
        // cout<<i<<endl;
        dp[i][i+1]=1;
        ans=2;
      }
    }
  }
  for (int ll = 3; ll <=len ; ll++)
  {
    for (int i = 0; i+ll-1<len ; i++)
    {
      int j= i+ll-1;
      if(store[i]==store[j]&&dp[i+1][j-1]==1){
        dp[i][j]=1;
        ans=ll;
      }
    }
  }
  cout<<ans;  
  return 0;
}