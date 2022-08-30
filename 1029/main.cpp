#include "bits/stdc++.h"
using namespace std;

vector<long int> list1;
int sizen;
void init()
{
  scanf("%d", &sizen);
  for (size_t i = 0; i < sizen; i++)
  {
    long int temp;
    scanf("%ld", &temp);
    list1.push_back(temp);
  }
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  init();
  init();
  sort(list1.begin(),list1.end());
  int index=list1.size()&1?list1.size()/2:list1.size()/2-1;
  printf("%ld",list1[index]);
  return 0;
}