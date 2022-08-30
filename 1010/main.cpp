#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
char first[32], second[32], temp[32];
LL tag, radix, result;
unordered_map<char, int> charToNum;
void Initial()
{
  //注意map这个容器的一些基本使用方法
  for (size_t i = 0; i < 36; i++)
  {
    charToNum.insert({i < 10 ? '0' + i : i - 10 + 'a', i});
  }
}
LL trans(char s[], LL radix)
{
  LL result = 0;
  for (size_t i = 0; s[i] != '\0'; i++)
  {
    result = result * radix + charToNum[s[i]];
  }
  return result;
}
LL findRadix(char first[], char second[], LL radix)
{
  LL firstValue = 0, leftValue = -1, midValue;
  firstValue = trans(first, radix);
  // cout << firstValue << endl;
  LL rightValue = firstValue + 1;
  for (size_t i = 0; second[i] != '\0'; i++)
  {
    leftValue = max(leftValue, (LL)charToNum[second[i]]);
  }
  leftValue++;
  while (leftValue < rightValue)
  {
    LL midRadix = leftValue + (rightValue - leftValue) / 2;
    midValue = 0;
    for (size_t i = 0; second[i] != '\0'; i++)
    {
      midValue = midValue * midRadix + charToNum[second[i]];
    }
    // cout << midValue << '/t' << "<----" << endl;
    if (midValue == firstValue)
    {
      return midRadix;
    }
    else if (midValue > firstValue || midValue < 0)
    {
      rightValue = midRadix - 1;
    }
    else
    {
      leftValue = midRadix + 1;
    }
  }
  midValue = 0;
  for (size_t i = 0; i < strlen(second); i++)
  {
    midValue = midValue * leftValue + charToNum[second[i]];
  }
  // cout << midValue << '/t' << "<----Last time" << endl;
  if (midValue == firstValue)
  {
    return leftValue;
  }
  else
    return -1;
}
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  Initial();
  // for (auto i : charToNum)
  // {
  //   /* code */
  //   cout << i.first << ' ' << i.second << endl;
  // }
  scanf("%s %s %lld %lld", first, second, &tag, &radix);
  result = tag == 1 ? findRadix(first, second, radix) : findRadix(second, first, radix);
  if (result == -1)
  {
    cout << "Impossible";
  }
  else
  {
    cout << result;
  }
  return 0;
}