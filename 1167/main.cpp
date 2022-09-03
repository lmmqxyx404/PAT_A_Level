#include "bits/stdc++.h"
using namespace std;
int n, store[32];
vector<int> res;
struct TreeNode
{
  int val;
  TreeNode *lchild, *rchild;
  TreeNode(int _val, TreeNode *_lchild = nullptr, TreeNode *_rchild = nullptr)
  {
    this->val = _val;
    this->lchild = _lchild;
    this->rchild = _rchild;
  }
};

TreeNode *buildTree(int ll, int rr)
{
  if (ll > rr)
    return nullptr;
  else
  {
    int min_num = INT32_MAX, tmp_index;
    for (int i = ll; i <= rr; i++)
    {
      if (store[i] < min_num)
      {
        min_num = store[i];
        tmp_index = i;
      }
    }
    auto root = new TreeNode(store[tmp_index], buildTree(ll, tmp_index - 1), buildTree(tmp_index + 1, rr));
    return root;
  }
}

void level_order(TreeNode *root)
{
  queue<TreeNode *> qq;
  qq.push(root);
  while (!qq.empty())
  {
    auto head = qq.front();
    qq.pop();
    res.push_back(head->val);

    if (head->lchild != nullptr)
    {
      qq.push(head->lchild);
    }
    if (head->rchild != nullptr)
    {
      qq.push(head->rchild);
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> n;
  for (size_t i = 0; i < n; i++)
  {
    cin >> store[i];
  }
  auto root = buildTree(0, n - 1);
  level_order(root);
  for (size_t i = 0; i < res.size(); i++)
  {
    printf("%s%d", i ? " " : "", res[i]);
  }
  return 0;
}