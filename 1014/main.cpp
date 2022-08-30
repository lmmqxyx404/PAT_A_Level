#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

const int startTime=8*60,endTime=17*60;

struct Customer
{
  int endTime,customer,window;
  Customer(int e,int c,int w){
    endTime=e,customer=c,window=w;
  }
  bool operator < (const Customer & tmp) const {
    return this->endTime > tmp.endTime;
  }
};

struct Window
{
  int windowIndex=0,personNum=0;
  Window(int w,int p){
    windowIndex=w,personNum=p;
  }
  bool operator < (const Window & tmp) const{
    if(this->personNum!=tmp.personNum){
      return this->personNum>tmp.personNum;
    }else {
      return this->windowIndex>tmp.windowIndex;
    }
  }
};

int n,m,k,q,processTime[1024],doneTime[1024],tailEndTime[22];
bool served[1024];
priority_queue<Window> window;
priority_queue<Customer> customer;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin>>n>>m>>k>>q;
  for (int i = 1; i <= k; i++)
  {
      cin>>processTime[i];
  }
  for (int i = 1; i <= k; i++)
  {
    if(window.size()<n){
      customer.push(Customer(startTime+processTime[i],i,window.size()));
      tailEndTime[window.size()]=startTime+processTime[i];
      window.push(Window(window.size(),1));
      doneTime[i]=startTime+processTime[i];
    }else {
      Window winTmp=window.top();
      if(winTmp.personNum<m){
        window.pop();
        window.push(Window(winTmp.windowIndex,winTmp.personNum+1));
        if(tailEndTime[winTmp.windowIndex]>=endTime){
          served[i]=true;
        }
        tailEndTime[winTmp.windowIndex]+=processTime[i];
        customer.push(Customer(tailEndTime[winTmp.windowIndex],i,winTmp.windowIndex));
        doneTime[i]=tailEndTime[winTmp.windowIndex];
      }else {
        Customer cusTmp=customer.top();
        customer.pop();
        if(tailEndTime[cusTmp.window]>=endTime) served[i]=true;
        tailEndTime[cusTmp.window]+=processTime[i];
        customer.push(Customer(tailEndTime[cusTmp.window],i,cusTmp.window));
        doneTime[i]=tailEndTime[cusTmp.window];
      }
    }
  }
  while (q--)
  {
    int tmp;
    cin>>tmp;
    if(served[tmp]){
      printf("Sorry\n");
    }else {
      printf("%02d:%02d\n",doneTime[tmp]/60,doneTime[tmp]%60);
    }
  }
  return 0;
}