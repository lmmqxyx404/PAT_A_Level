#include "bits/stdc++.h"
using namespace std;

int n,pre,now,change,ans;
int main(){
  freopen("Text.txt","r",stdin);
  freopen("Text1.txt","w",stdout);
  cin>>n;
  while (n--)
  {
    cin>>now;
    change=now-pre;
    if(change>=0){
      ans+=change*6+5;
    }
    else
    {
      ans+=-1*change*4+5;
    }
    pre=now;
  }
  cout<<ans;
  return 0;
}