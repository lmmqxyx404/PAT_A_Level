#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

int n;
string ini;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin>>n;
  for (size_t i = 0; i < n; i++)
  {
    cin>>ini;
    int len=ini.size(),leftN,rightN;
    string leftS=ini.substr(0,len/2),rightS=ini.substr(len/2,len/2);
    if(stoi(ini)%(stoi(leftS)*stoi(rightS))){
      cout<<"No"<<endl;
    }else {
      cout<<"Yes"<<endl;      
    }
  }
  
  return 0;
}