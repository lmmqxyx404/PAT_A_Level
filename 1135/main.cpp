#include "bits/stdc++.h"
using namespace std;
int k, n, storeData[32], isRBT, nodenum;
vector<int> path;
struct Node
{
  int data;
  Node *lchild, *rchild;
  Node(int val)
  {
    data = val;
    lchild = nullptr;
    rchild = nullptr;
  }
};
Node *buildTree(int prel, int prer)
{
  if (prel > prer)
    return nullptr;
  Node *root = new Node(storeData[prel]);
  int flag = -1;
  for (int i = prel + 1; i <= prer; i++)
  {
    if (abs(storeData[i]) > abs(storeData[prel]))
    {
      flag = i;
      break;
    }
  }
  if (flag == -1)
  {
    root->rchild = nullptr;
    root->lchild = buildTree(prel + 1, prer);
  }
  else
  {
    root->rchild = buildTree(flag, prer);
    root->lchild = buildTree(prel + 1, flag - 1);
  }
  return root;
}
void traverse(Node *root)
{
  if (root == nullptr)
  {
    int count = 1;
    for (auto i : path)
    {
      if (i > 0)
        count++;
    }
    nodenum=nodenum==-1?count:nodenum;
    if(nodenum!=count){
      isRBT=false;
    }
    return;
  }
  path.push_back(root->data);
  if(root->data<0){
    if(root->lchild!=nullptr){
      if(root->lchild->data<0) {
        isRBT=false;
        return;
      }
    }
    if(root->rchild!=nullptr){
      if(root->rchild->data<0) {
        isRBT=false;
        return;
      }
    }
  }
  if(isRBT) traverse(root->lchild);
  if(isRBT) traverse(root->rchild);
  path.pop_back();
}
bool isRBTree()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> storeData[i];
  }
  Node *root = buildTree(1, n);
  if(root->data<0) return false;
  isRBT = true;
  path.clear();
  nodenum = -1;
  traverse(root);
  return isRBT;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    printf("%s%s", i ? "\n" : "", isRBTree() ? "Yes" : "No");
  }
  return 0;
}