#include "bits/stdc++.h"
using namespace std;

struct node
{
  int val, next;
} nodes[100024];
struct fullnode
{
  int address, val, next;
};
vector<fullnode> llfn, ssfn, answer;
int n, lsp, ssp;

void initialize(int sp, vector<fullnode> &res)
{
  while (sp != -1)
  {
    fullnode tmpfn{sp, nodes[sp].val, nodes[sp].val};
    res.push_back(tmpfn);
    sp = nodes[sp].next;
  }
}
void merge(vector<fullnode> &llfnode, vector<fullnode> &ssfnode)
{
  int llen = llfnode.size(), sslen = ssfnode.size();
  int counterll = 0, counterss = sslen - 1;
  while (counterll < llen || counterss >= 0)
  {
    for (int i = 0; i < 2 && counterll < llen; i++)
    {
      answer.push_back(llfnode[counterll++]);
    }
    if (counterss >= 0)
    {
      answer.push_back(ssfnode[counterss--]);
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
  cin >> lsp >> ssp >> n;
  for (size_t i = 0; i < n; i++)
  {
    int aa, ss, dd;
    scanf("%d %d %d", &aa, &ss, &dd);
    node tmp{ss, dd};
    nodes[aa] = tmp;
  }
  initialize(lsp, llfn);
  initialize(ssp, ssfn);
  if (llfn.size() < ssfn.size())
  {
    merge(ssfn, llfn);
  }
  else
  {
    merge(llfn, ssfn);
  }
  int i = 0;
  for (; i < answer.size() - 1; i++)
  {
    printf("%05d %d %05d\n", answer[i].address, answer[i].val, answer[i + 1].address);
  }
  printf("%05d %d -1", answer[i].address, answer[i].val);
  return 0;
}