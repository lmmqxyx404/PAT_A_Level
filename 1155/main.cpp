#include "bits/stdc++.h"
using namespace std;
int store[1024], n, level, tmp;
bool visit[2048], isPrint[2044], isMaxHeap;
vector<int> answer;
bool cmp(int a, int b)
{
  if (a >= pow(2, level - 1) && b >= pow(2, level - 1))
    return a > b;
  if (a < pow(2, level - 1) && b < pow(2, level - 1))
    return a > b;
  return a < b;
}
void writeDown(int leaf)
{
  vector<int> key;
  while (leaf)
  {
    key.push_back(leaf);
    leaf /= 2;
  }
  reverse(key.begin(), key.end());
  for (auto i = 0; i < key.size(); i++)
  {
    printf("%d%s", store[key[i]], i == key.size() - 1 ? "\n" : " ");
  }
}
bool judge(int root,int lc,int rc){
  if(isMaxHeap!=(store[root]>store[lc])) return false;
  if(rc<=n){
    if(isMaxHeap!=(store[root]>store[rc])) return false;
  }
  return true;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  //  ios::sync_with_stdio(false);
  cin >> n;
  fill(visit + 1, visit + n + 1, true); //it can also be changed by the 17th line;
  for (size_t i = 1; i <= n; i++)
  {
    cin >> store[i];
  }
  tmp = n;
  isMaxHeap = store[1] > store[2];

  while (tmp)
  {
    level++;
    tmp /= 2;
  }
  for (int i = n / 2 + 1; i <= n; i++)
  {
    answer.push_back(i);
  }
  sort(answer.begin(), answer.end(), cmp);
  for (auto i : answer)
  {
    //cout<<"footer is "<<i<<endl;
    writeDown(i);
  }
  for (int i = 1; i <= n / 2; i++)
  {
    int leftChild = i * 2, rightChild = leftChild + 1;
    if(!judge(i,leftChild,rightChild))
    {
      
      printf("Not Heap");
      return 0;
    }
  }
  printf("%s",isMaxHeap?"Max Heap":"Min Heap");
  return 0;
}

void process(int root)
{
  if (!visit[root])
  {
    if (isPrint[root / 2])
      return;
    isPrint[root / 2] = true;
    for (auto i = 0; i < answer.size(); i++)
    {
      printf("%d%s", store[answer[i]], i == answer.size() - 1 ? "\n" : " ");
    }
    answer.erase(answer.end() - 1);
    return;
  }
  answer.push_back(root);
  process(root * 2 + 1);
  process(root * 2);
}