  #include "bits/stdc++.h"
  using namespace std;
  #define endl "\n"
  const int BlockNumber= ceil(sqrtf(1e5+1));
  int storeNumber[100010],N,block[320];
  stack<int> store; // The main function is to judge if it is empty
  int getPeekMedian(int total){
    int indexAccount=0,writeDown=-1;
    for (int i = 0; i < 318; i++)
    {
      indexAccount+=block[i];
      if(indexAccount>=total){
        indexAccount-=block[i];
        writeDown=i;
        break;
      }
    }
    for (int i = writeDown*316; i < writeDown*316+316; i++) //watch out do not forget to let writeDown*(316+1)
    {
      if(indexAccount+storeNumber[i]>=total){
        return i;
      }else {                                               //remember to let indexAccount accumulate
        indexAccount+=storeNumber[i];   
      }
    }
    return -1;
  }
  int main()
  {
    freopen("Text.txt", "r", stdin);
    freopen("Text1.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>N;
    while (N--)
    {
      string tmp;
      cin>>tmp;
      int answer;
      if(tmp=="Pop"){
        if(store.empty()){
          cout<<"Invalid"<<endl;
        }else {
          answer=store.top();
          store.pop();
          block[answer/316]--;
          storeNumber[answer]--;
          cout<<answer<<endl;
        }
      }else if(tmp=="Push"){
        cin>>answer;
        store.push(answer);
        storeNumber[answer]++;
        block[answer/316]++;
      }else {
        if(store.empty()){
          cout<<"Invalid"<<endl;
        }else {
          cout<<getPeekMedian((store.size()+1)/2)<<endl;
        }
      }
    }
    return 0;
  }