#include <bits/stdc++.h>
using namespace std;
class beads{
  public:
  unordered_map<char,int> mp;
  beads(){
    cin>>store;
    length=store.length();
    for (int i = 0; i < length; i++)
    {
      mp[store[i]]++;
    }
  }
  string getstr(){
    return store;
  }
  int judge(beads sale){
    int result=0;
    for (auto i: mp)
    {
      char tmp2=i.first;
      int tmp3=i.second;
      if(sale.mp[tmp2]<tmp3){
        result+=sale.mp[tmp2]-tmp3;
      }
    }
    if(result<0) return result;
    return sale.getstr().length()-length;
  }
  private:
    string store;
    int length;
};
int main(){
  freopen("Text.txt","r",stdin);
  freopen("Text1.txt","w",stdout);
  beads sale,origin;
  if(origin.judge(sale)<0){
    printf("No %d",origin.judge(sale)*-1);
  }
  else
  {
    printf("Yes %d",origin.judge(sale));
  } 
  return 0;
}