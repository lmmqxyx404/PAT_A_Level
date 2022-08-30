#include <bits/stdc++.h>
using namespace std;

int N,M,tmp1,tmp2;;
unordered_map<int,int> couples;
set<int> store;
int main(){
  freopen("Text.txt","r",stdin);
  freopen("Text1.txt","w",stdout);
  scanf("%d",&N);
  while (N--)
  {
    scanf("%d %d",&tmp1,&tmp2);
    couples[tmp1]=tmp2;
    couples[tmp2]=tmp1;
  }
  scanf("%d",&M);
  while (M--)
  {
    scanf("%d",&tmp1);
    if(couples.count(tmp1)&&store.find(couples[tmp1])!=store.end()){
      store.erase(couples[tmp1]);
    }
    else
    {
      store.insert(tmp1);
    }
  }
  printf("%d\n",store.size());
  if(!store.size()) return 0;
  for (auto i = store.begin(); ;)
  {
    printf("%05d",*i);
    i++;
    if(i!=store.end()){
      printf(" ");
    }else break;
  }
  return 0;
}