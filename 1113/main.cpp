#include "bits/stdc++.h"
using namespace std;

int store[100024],n,l,r;
int main(){
  freopen("Text.txt","r",stdin);
  freopen("Text1.txt","w",stdout);
  cin>>n;
  for (size_t i = 0; i < n; i++)
  {
    cin>>store[i];
  }
  sort(store,store+n);
  for (size_t i = 0; i < n; i++)
  {
    if(i<n/2){
      l+=store[i];
    }
    else
    {
      r+=store[i];
    }
  }
  if(n&1){
    printf("1 %d",r-l);
  }
  else
  {
    printf("0 %d",r-l);
  }
  return 0;
}