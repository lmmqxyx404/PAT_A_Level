  #include "bits/stdc++.h"
  using namespace std;
  int minNum = 0x7fffffff;
  int pre[100024], store[100024], total, num, leftIndex, rightIndex = 1, flag;
  vector<int> ans;
  int main()
  {
    freopen("Text.txt", "r", stdin);
    freopen("Text1.txt", "w", stdout);
    cin >> num >> total;
    for (int i = 1; i <= num; i++)
    {
      cin >> store[i];
      pre[i] = pre[i - 1] + store[i];
    }
    while (rightIndex <= num)
    {
      /* code */
      int tmp = pre[rightIndex] - pre[leftIndex] - total;
      if (tmp < 0)
      {
        rightIndex++;
      }
      else if (tmp == 0)
      {
        if (flag != 2)
        {
          ans.clear();
        }
        flag = 2;
        ans.push_back(leftIndex + 1);
        ans.push_back(rightIndex);
        leftIndex++;
        rightIndex++;
      }
      else
      {
        if (flag == 2)
        {
          leftIndex++;
          if (leftIndex == rightIndex)
          {
            rightIndex++;
          }
          continue;
        }
        if (tmp < minNum)
        {
          flag = 1;
          minNum = tmp;
          ans.clear();
          ans.push_back(leftIndex + 1);
          ans.push_back(rightIndex);
        }
        else if (tmp == minNum)
        {
          ans.push_back(leftIndex + 1);
          ans.push_back(rightIndex);
        }
        leftIndex++;
        if (leftIndex == rightIndex)
        {
          rightIndex++;
        }
      }
    }
    for (int i = 0; i < ans.size();)
    {
      /* code */
      printf("%d-%d", ans[i], ans[i + 1]);
      i += 2;
      if (i < ans.size())
      {
        printf("\n");
      }
    }
    return 0;
  }