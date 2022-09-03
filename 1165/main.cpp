#include "bits/stdc++.h"
using namespace std;

string sp;
int total, block_num, counter;
struct node
{
  string data, next;
};
struct full_node
{
  string address, data, next;
};
vector<vector<full_node>> store;
vector<full_node> tmp_store;
unordered_map<string, node> address_mp;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
#endif
  //  ios::sync_with_stdio(false);
  cin >> sp >> total >> block_num;
  // cout << sp << total << block_num;
  for (size_t i = 0; i < total; i++)
  {
    string tmp_add, tmp_data, tmp_next;
    cin >> tmp_add >> tmp_data >> tmp_next;
    node tmp_node{tmp_data, tmp_next};
    address_mp.insert({tmp_add, tmp_node});
  }
  while (true)
  {
    full_node tmp_fullnode{sp, address_mp[sp].data, address_mp[sp].next};
    tmp_store.push_back(tmp_fullnode);
    if (tmp_store.size() == block_num)
    {
      store.push_back(tmp_store);
      tmp_store.clear();
    }
    if (address_mp[sp].next == "-1")
    {
      if (!tmp_store.empty())
      {
        store.push_back(tmp_store);
        tmp_store.clear();
      }
      break;
    }
    else
      sp = address_mp[sp].next;
  }
  reverse(store.begin(), store.end());
  for (size_t i = 0; i < store.size(); i++)
  {
    auto &tmp_block = store[i];
    if (i == store.size() - 1)
    {
      full_node &tail = tmp_block.back();
      tail.next = "-1";
    }
    else
    {
      full_node &tail = tmp_block.back();
      tail.next = store[i + 1][0].address;
    }
  }
  for (auto i : store)
  {
    for (auto j : i)
    {
      cout << j.address << " " << j.data << " " << j.next << endl;
    }
  }
  return 0;
}