#include "bits/stdc++.h"
using namespace std;

int n, pos[32], inorder[32], m, father[1024];
bool isfull = true;
struct node
{
  int val, level;
  node *lchild, *rchild;
  node(int a, node *l = nullptr, node *r = nullptr, int ll = -1)
  {
    this->val = a;
    this->lchild = l;
    this->rchild = r;
    this->level = ll;
  }
};
unordered_map<int, node *> mp;
node *buidltree(int inl, int inr, int posl, int posr, node *fathernode = nullptr)
{
  if (inl > inr)
    return nullptr;
  int rootval = pos[posr], index;
  for (int i = inl; i <= inr; i++)
  {
    if (inorder[i] == rootval)
    {
      index = i;
      break;
    }
  }
  int llen = index - inl;
  auto root = new node(rootval);
  father[rootval] = fathernode ? fathernode->val : -1;
  root->level = fathernode ? fathernode->level + 1 : 1;
  mp[rootval] = root;
  root->lchild = buidltree(inl, index - 1, posl, posl + llen - 1, root);
  root->rchild = buidltree(index + 1, inr, posl + llen, posr - 1, root);
  isfull = isfull && ((root->lchild == nullptr && root->rchild == nullptr) || (root->lchild != nullptr && root->rchild != nullptr));
  return root;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  for (int i = 1; i <= 1000; i++)
    father[i] = i;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> pos[i];
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> inorder[i];
  }
  auto root = buidltree(1, n, 1, n);
  string ss;
  cin >> m;
  getchar();
  // levelorder(root);
  for (int i = 1; i <= m; i++)
  {
    getline(cin, ss);
    if (ss.find("root") != ss.npos)
    {
      int root_val;
      sscanf(ss.c_str(), "%d is the root", &root_val);
      printf("%s\n", root_val == root->val ? "Yes" : "No");
    }
    else if (ss.find("siblings") != ss.npos)
    {
      int aa, dd;
      sscanf(ss.c_str(), "%d and %d are siblings", &aa, &dd);
      bool flag = aa != dd && mp[aa]->level == mp[dd]->level;
      bool res = flag ? (father[aa] == father[dd]) : flag;
      printf("%s\n", res ? "Yes" : "No");
    }
    else if (ss.find("parent") != ss.npos)
    {
      int aa, dd;
      sscanf(ss.c_str(), "%d is the parent of %d", &aa, &dd);
      bool res = aa != dd && aa == father[dd];
      printf("%s\n", res ? "Yes" : "No");
    }
    else if (ss.find("left") != ss.npos)
    {
      int aa, dd;
      sscanf(ss.c_str(), "%d is the left child of %d", &aa, &dd);
      auto ddnode = mp[dd];
      bool res = ddnode->lchild == mp[aa];
      printf("%s\n", res ? "Yes" : "No");
    }
    else if (ss.find("right") != ss.npos)
    {
      int aa, dd;
      sscanf(ss.c_str(), "%d is the right child of %d", &aa, &dd);
      auto ddnode = mp[dd];
      bool res = ddnode->rchild == mp[aa];
      printf("%s\n", res ? "Yes" : "No");
    }
    else if (ss.find("same") != ss.npos)
    {
      int aa, dd;
      sscanf(ss.c_str(), "%d and %d are on the same level", &aa, &dd);
      bool res = mp[aa]->level == mp[dd]->level;
      printf("%s\n", res ? "Yes" : "No");
    }
    else
    {
      printf("%s\n", isfull ? "Yes" : "No");
    }
  }
  return 0;
}

/* void levelorder(node *root)
{
  queue<node *> qq;
  root->level = 1;
  qq.push(root);
  father[root->val] = root->val;
  while (!qq.empty())
  {
    auto head = qq.front();
    mp[head->val] = head;
    qq.pop();
    isfull = isfull ? isfull : ((head->lchild == nullptr && head->rchild == nullptr) || (head->lchild != nullptr && head->rchild != nullptr));
    if (head->lchild)
    {
      father[head->lchild->val] = head->val;
      head->lchild->level = head->level + 1;
      qq.push(head->lchild);
    }
    if (head->rchild)
    {
      father[head->rchild->val] = head->val;
      head->rchild->level = head->level + 1;
      qq.push(head->rchild);
    }
  }
} */