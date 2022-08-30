#include "bits/stdc++.h"
using namespace std;
int store[1024],n,m;
void postorder(int root){
  if(root>n) return;
  postorder(root*2);
  postorder(root*2+1);
  printf("%d%s",store[root],root==1?"\n":" ");
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin>>m>>n;
  for (size_t i = 0; i < m; i++)
  {
    cin>>store[1]>>store[2];
    bool isMaxHeap=store[1]>store[2],isHeap=true;
    for (int j = 3; j <= n; j++)
    {
      cin>>store[j];
      if(isHeap){
        if(isMaxHeap==store[j/2]>store[j]);
        else isHeap=false;
      }
      // if(isHeap&& (isMaxHeap!=store[j]>store[j/2])){
      //   isHeap==false;
      // }
    }
    printf("%s\n",isHeap?isMaxHeap?"Max Heap":"Min Heap":"Not Heap");
    postorder(1);
  }
  
  return 0;
}