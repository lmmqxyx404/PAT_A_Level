#include "bits/stdc++.h"
using namespace std;
int m, n, pre[10024];
unordered_map<int, int> visit, father, level;
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
int getAncestor(int former, int latter)
{
  if (level[former] <= level[latter])
  {
    swap(former, latter);
  }
  for (int i = level[former]; i > level[latter]; i--)
  {
    former=father[former];
  }
  while (former != latter)
  {
    former = father[former];
    latter = father[latter];
  }
  return former;
}
void levelTraverse(Node *root, int currentLevel, int myFather)
{
  if (root == nullptr)
    return;
  level[root->data] = currentLevel;
  father[root->data] = myFather;
  levelTraverse(root->lchild, currentLevel + 1, root->data);
  levelTraverse(root->rchild, currentLevel + 1, root->data);
}
Node *buildTree(int prel, int prer)
{
  if (prel > prer)
    return nullptr;
  Node *root = new Node(pre[prel]);
  int flag = -1;
  int i = prel + 1;
  for (; i <= prer; i++)
  {
    if (pre[i] > pre[prel])
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
    root->lchild = buildTree(prel + 1, flag - 1);
    root->rchild = buildTree(flag, prer);
  }
  return root;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  //  ios::sync_with_stdio(false);
  cin >> m >> n;
  for (size_t i = 1; i <= n; i++)
  {
    scanf("%d",&pre[i]);
    visit[pre[i]] = true;
  }
  Node *root = buildTree(1, n);
  levelTraverse(root, 1, root->data);
  for (size_t i = 0; i < m; i++)
  {
    int former, latter;
    scanf("%d %d",&former,&latter);
    if (!visit[former] && !visit[latter])
    {
      printf("ERROR: %d and %d are not found.", former, latter);
    }
    else if (visit[former] && visit[latter])
    {
      int commenFather = getAncestor(former, latter);
      if (former == commenFather || latter == commenFather)
      {
        if (latter == commenFather)
          swap(former, latter);
        printf("%d is an ancestor of %d.", former, latter);
      }
      else
      {
        printf("LCA of %d and %d is %d.", former, latter, commenFather);
      }
    }
    else
    {
      printf("ERROR: %d is not found.", visit[latter] ? former : latter);
    }
    printf("%s", i == m - 1 ? "" : "\n");
  }
  return 0;
}