#include "bits/stdc++.h"
using namespace std;

int store[100024],n;
bool cmp(int q,int w){
  return q>w;
}
int main(){
  freopen("Text.txt","r",stdin);
  freopen("Text1.txt","w",stdout);
  cin>>n;
  for (size_t i = 0; i < n; i++)
  {
    cin>>store[i];
  }
  sort(store,store+n,cmp);
  for (size_t i = 0; i < n; i++)
  {
    if(store[i]<=i+1) {
      cout<<i;
      return 0;
    }
  }
  cout<<n;
  return 0;
}