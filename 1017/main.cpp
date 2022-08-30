#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
const int terminal = 17 * 3600;
struct Node
{
  int totalSeconds, processSeconds;
};
vector<Node> store;

int n, k, sumSeconds,cnt;
priority_queue<int, vector<int>, greater<int>> bankQ;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int hh, mm, ss, procSec;
    scanf("%d:%d:%d %d", &hh, &mm, &ss, &procSec);
    Node tmp = {hh * 3600 + mm * 60 + ss, procSec * 60};
    if (tmp.totalSeconds <= terminal)
      store.push_back(tmp);
  }
  for (int i = 0; i < k; i++)
  {
    bankQ.push(8 * 3600);
  }
  sort(store.begin(), store.end(), [](Node &asd, Node &qwe) { return asd.totalSeconds < qwe.totalSeconds; });
  for ( int i = 0; i < store.size(); i++,cnt++)
  {
    
    // cout << store[i].totalSeconds << " " << store[i].processSeconds << endl;
    int tmp = bankQ.top();
    bankQ.pop();
    // cout << "tmp is " << tmp << endl;
    /*  If a customer arrives before 17:00:01, then he must be served;
    if (tmp > terminal)
    {
      break;
    }
    */
    if (tmp >= store[i].totalSeconds)
    {
      sumSeconds += tmp - store[i].totalSeconds;
      tmp += store[i].processSeconds;
    }
    else
      tmp = store[i].totalSeconds + store[i].processSeconds;
    bankQ.push(tmp);
  }
  if(sumSeconds==0||cnt==0){
    cout<<"0.0"<<endl;
  }
  else printf("%.1f\n", (double)sumSeconds * 1.0 / (cnt*1.0 )/ 60.0);
  return 0;
}