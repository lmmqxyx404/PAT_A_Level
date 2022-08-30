#include "bits/stdc++.h"
using namespace std;

double capacityOfTank, disFromHZ, davg, numStations, carDis, minCost, maxDis, currentGas, minPrice = 0x7fffffff;
struct Station
{
  double dis, gasPrice;
} tmp, now;
vector<Station> store;
bool cmp(Station a, Station s)
{
  return a.dis != s.dis ? a.dis < s.dis : a.gasPrice < s.gasPrice;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> capacityOfTank >> disFromHZ >> davg >> numStations;
  carDis = davg * capacityOfTank; //计算最大车辆最远行驶距离
  for (size_t i = 0; i < numStations; i++)
  {
    cin >> tmp.gasPrice >> tmp.dis;
    store.push_back(tmp);
  }
  store.push_back({disFromHZ, 0});
  sort(store.begin(), store.end(), cmp);
  if (store[0].dis)
  {
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  for (size_t i = 1; i <= numStations;)
  {
    now = store[i - 1];
    int flag = -1, index = -1;
    minPrice = 0x7fffffff;
    // 先确认好加油站的位置，再统一计算价格
    while (store[i].dis - now.dis <= carDis && i <= numStations)
    {
      if (store[i].gasPrice <= now.gasPrice)
      {
        index = i;
        flag = 2;
        i++;
        break;
      }
      else
      {
        if (store[i].gasPrice < minPrice)
        {
          flag = 1;
          index = i;
          minPrice = store[i].gasPrice;
        }
      }
      i++;
    }
    if (flag == -1)
    {
      printf("The maximum travel distance = %.2f", now.dis + carDis);
      return 0;
    }
    else if (flag == 2)
    {
      double requiredGas = (store[index].dis - now.dis) / davg - currentGas;
      minCost += requiredGas * now.gasPrice;
      currentGas = 0;
    }
    else
    {
      double requiredGas = capacityOfTank - currentGas;
      minCost += requiredGas * now.gasPrice;
      currentGas = capacityOfTank - ((store[index].dis - now.dis) / davg);
    }
    i = index + 1;  //千万要注意索引,表明当前到达了第几个加油站
  }
  printf("%.2f", minCost);
  return 0;
}