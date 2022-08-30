#include "bits/stdc++.h"
using namespace std;

class mooncake
{
private:
public:
  double num, price, per;
  mooncake(double num, double price);
  void getPer();
  ~mooncake();
  bool operator<(const mooncake &sad)
  {
    return per < sad.per;
  }
};

mooncake::mooncake(double num = 0, double price = 0)
{
  this->num = num;
  this->price = price;
}
void mooncake::getPer()
{
  this->per = this->num / this->price;
}
mooncake::~mooncake()
{
}

int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  mooncake store[1024];
  int number;
  double required, answer = 0;
  cin >> number >> required;
  for (size_t i = 0; i < number; i++)
  {
    cin >> store[i].num;
  }
  for (size_t i = 0; i < number; i++)
  {
    cin >> store[i].price;
    store[i].getPer();
  }
  sort(store, store + number);
  for (size_t i = 0; i < number; i++)
  {
    if (required > store[i].num)
    {
      required -= store[i].num;
      answer += store[i].price;
    }
    else
    {
      answer += required / store[i].num * store[i].price;
      break;
    }
  }
  printf("%.2f", answer); //注意输出格式
  return 0;
}