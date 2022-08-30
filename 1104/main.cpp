#include "bits/stdc++.h"
using namespace std;

double store[100024],n;
double tmp[100024],ans;
int main(){
  freopen("Text.txt","r",stdin);
  freopen("Text1.txt","w",stdout);
  cin>>n;
  for (int i = 1; i <= n; i++)
  {
    store[i]=(n-i+1)*i; 
    cin>>tmp[i];
  }
  for (int i = 1; i <=n ; i++)
  {
    ans+=tmp[i]*store[i];
  }
  printf("%.2lf",ans);
  return 0;
}