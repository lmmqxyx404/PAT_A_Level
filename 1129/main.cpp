#include "bits/stdc++.h"
using namespace std;
bool visit[50024];
int n, k, tmp, counter[50024], portrayIndex[50024];
vector<int> store;
list<int> assemblyLine;

int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  scanf("%d %d %d", &n, &k, &tmp);
  counter[tmp]++;
  store.push_back(tmp);
  portrayIndex[tmp] = 0;
  visit[tmp] = true;
  for (size_t i = 0; i < n - 1; i++)
  {
    scanf("%d", &tmp);
    printf("%d:", tmp);
    int add = 0;
    for (auto &j : store)
    {
      add++;
      if (add > k)
      {
        break;
      }
      else
        printf(" %d", j);
    }
    printf("\n");
    counter[tmp]++;
    if (!visit[tmp])
    {
      if (store.size() < k)
      {
        store.push_back(tmp);
        portrayIndex[tmp] = store.size() - 1;
        visit[tmp]=true;
      }
      else if (store.size() == k)
      {
        if (counter[tmp] > counter[*(store.end() - 1)])
        {
          visit[*(store.end() - 1)]=false;
          store.erase(store.end() - 1);
          store.push_back(tmp);
          portrayIndex[tmp] = store.size() - 1;
          visit[tmp]=true;
        }
        else if ((counter[tmp] == counter[*(store.end() - 1)]) && tmp < *(store.end() - 1))
        {
          visit[*(store.end() - 1)]=false;
          visit[tmp]=true;
          store.erase(store.end() - 1);
          store.push_back(tmp);
          portrayIndex[tmp] = store.size() - 1;
        }
        else
          continue;
      }
    }
    while (portrayIndex[tmp] > 0)
    {
      int adjacent = portrayIndex[tmp] - 1;
      // cout << "now:\t" << tmp << counter[tmp] << portrayIndex[tmp] << endl;
      // cout << "former:\t" << store[adjacent] << counter[store[adjacent]] << portrayIndex[store[adjacent]] << endl;
      if (counter[tmp] > counter[store[adjacent]])
      {
        portrayIndex[tmp] -= 1;
        portrayIndex[store[adjacent]] += 1;
        swap(store[adjacent], store[adjacent + 1]);
      }
      else if (counter[tmp] == counter[store[adjacent]] && tmp < store[adjacent])
      {
        portrayIndex[tmp] -= 1;
        portrayIndex[store[adjacent]] += 1;
        swap(store[adjacent], store[adjacent + 1]);
      }
      else
        break;
    }
  }
  return 0;
}