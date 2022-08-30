#include "bits/stdc++.h"
using namespace std;

struct people
{
  string name;
  int height;
} tmp;
vector<people> store,temp;
int n, k, counter;
vector<vector<people> >ans;
bool cmp(people a, people s)
{
  if (a.height == s.height)
  {
    return a.name < s.name;
  }
  return a.height > s.height;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp.name >> tmp.height;
    store.push_back(tmp);
  }
  sort(store.begin(),store.end() , cmp);
/*  if(k==1){
    for (size_t i = 0; i < store.size(); i++)
    {
      printf("%s%s",i?"\n":"",store[i].name.c_str());
    }
    return 0;
  }*/
  for (int j = 0; j < k; j++)
  {
    int i = j ? n/k : n/k+n%k;
    for (int q = 0; q < i; q++){
      if(q&1){
        temp.insert(temp.begin(),store[counter+q]);
      }
      else temp.push_back(store[counter+q]);
    }
    counter+=i;
    ans.push_back(temp);
    temp.clear();
  }
  for (size_t i = 0; i < ans.size(); i++)
  {
    for (size_t j = 0; j < ans[i].size(); j++)
    {
      printf("%s",ans[i][j].name.c_str());
      if(j!=ans[i].size()-1) cout<<" ";
    }
    if(i!=ans.size()-1) cout<<'\n';
  }
  return 0;
}