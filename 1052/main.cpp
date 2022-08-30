#include "bits/stdc++.h"
using namespace std;

struct Node
{
  int address, value;
} temporary, indexLink[1000024];
vector<Node> store;
int startLink, num, indexOfList;
bool cmp(Node a, Node s)
{
  return a.value < s.value;
}
// pay more attention to the last test point . link list can be empty.
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> num >> startLink;
  for (size_t i = 0; i < num; i++)
  {
    cin >> indexOfList;
    cin >> indexLink[indexOfList].value >> indexLink[indexOfList].address;
  }
  while (startLink != -1)
  {
    temporary.address = startLink;
    temporary.value = indexLink[startLink].value;
    store.push_back(temporary);
    startLink = indexLink[startLink].address;
  }
  sort(store.begin(), store.end(), cmp);
  if (store.size() == 0)
  {
    printf("0 -1");
    return 0;
  }
  printf("%d %05d\n", store.size(), store[0].address);
  for (size_t i = 0; i < store.size(); i++)
  {
    printf("%05d %d ", store[i].address, store[i].value);
    if (i != store.size() - 1)
    {
      printf("%05d\n", store[i + 1].address);
    }
    else
    {
      printf("-1");
      return 0;
    }
  }

  return 0;
}