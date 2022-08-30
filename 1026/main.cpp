#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
const int closeTime = 21 * 3600;
struct Player
{
  int arriveTime = 0, processTime = 0;
  bool vip = false;
};

struct Table
{
  bool occupy = false, vip = false;
  int servePlayerNum = 0;
};

Player player[10024];

Table table[108];

struct PlayerTable
{
  int tableIndex, playerIndex, t_time; //t-time means different field
  PlayerTable(int t, int p, int tt)
  {
    tableIndex = t, playerIndex = p, t_time = tt;
  }
  bool operator <(const PlayerTable &tmp) const
  {
    return this->t_time > tmp.t_time;
  }
};
priority_queue<PlayerTable> playerTable;
list<int> waiting;

int n, m, k;
int searchTable(bool vip)
{
  if (vip)
  {
    for (int i = 1; i <= k; i++)
    {
      if (!table[i].occupy && table[i].vip)
        return i;
    }
  }
   
    for (int i = 1; i <= k; i++)
    {
      if (!table[i].occupy)
        return i;
    }
  
  return -1;
}
void outputFormat(int arrive, int terminal)
{
  printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arrive / 3600, arrive / 60 % 60, arrive % 60, terminal / 3600, terminal / 60 % 60, terminal % 60, (terminal - arrive + 30) / 60);
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int hh, mm, ss;
    player[i].arriveTime = closeTime;
    scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &player[i].processTime, &player[i].vip);
    player[i].arriveTime = hh * 3600 + mm * 60 + ss;
    player[i].processTime = min(player[i].processTime, 120);
    player[i].processTime *= 60;
    playerTable.push(PlayerTable(0, i, player[i].arriveTime));
  }
  cin >> k >> m;
  for (int i = 0; i < m; i++)
  {
    int tmp;
    cin >> tmp;
    table[tmp].vip = true;
  }
  while (!playerTable.empty())
  {
    PlayerTable pt = playerTable.top();
    playerTable.pop();
    // cout<<"pt is "<<pt.playerIndex<<" "<<pt.t_time<<" "<<pt.tableIndex<<endl;
    if (pt.t_time >= closeTime)
      break; // >
    if (pt.tableIndex == 0)
    {
      int index = searchTable(player[pt.playerIndex].vip);
      if (index != -1)
      {
        table[index].occupy = true;
        int endTime = pt.t_time + player[pt.playerIndex].processTime;
        playerTable.push(PlayerTable(index, pt.playerIndex, endTime));
        outputFormat(player[pt.playerIndex].arriveTime, pt.t_time);
        table[index].servePlayerNum++;
        // cout<<"1 "<<index<<endl;
      }
      else
      {
        waiting.push_back(pt.playerIndex);
      }
    }
    else
    {
      if (waiting.empty())
      {
        table[pt.tableIndex].occupy = false;
      }
      else
      {
        int tmp;
        if (!table[pt.tableIndex].vip)
        {
          tmp = waiting.front();
          waiting.pop_front();
        }
        else
        {
          auto i = waiting.begin();
          while (i != waiting.end() && (!player[*i].vip))
          {
            ++i;
          }
          if (i == waiting.end())
          {
            tmp = waiting.front();
            waiting.pop_front();
          }
          else
          {
            tmp = *i;
            waiting.erase(i);
          }
        }
        int endTime = pt.t_time + player[tmp].processTime;
        playerTable.push(PlayerTable(pt.tableIndex, tmp, endTime));
        outputFormat(player[tmp].arriveTime, pt.t_time);
        ++table[pt.tableIndex].servePlayerNum;
        // cout<<"2 "<<pt.tableIndex<<endl;
      }
    }
  }

  for (int i = 1; i <= k; ++i)
  {
    printf("%s%d", i > 1 ? " " : "", table[i].servePlayerNum);
  }
  return 0;
}