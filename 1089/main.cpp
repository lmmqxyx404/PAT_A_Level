#include "bits/stdc++.h"
using namespace std;
int ini[110], target[110], store[110], n;
bool isInsert;
int main()
{
  freopen("Text.txt", "r", stdin);
  freopen("Text1.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> n;
  for (size_t i = 0; i < n; i++)
  {
    cin >> ini[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    cin >> target[i];
  }
  memcpy(store, ini, sizeof(ini));
  for (size_t i = 1; i < n; i++)
  {
    sort(store, store + i + 1);
    if (equal(store, store + n, target, target + n))
    {
      isInsert = true;
      cout << "Insertion Sort" << endl;
      sort(store, store + i + 2);
      for (size_t i = 0; i < n; i++)
      {
        printf("%s%d", i ? " " : "", store[i]);
      }
      break;
    }
  }
  if (!isInsert)
  {
    memcpy(store, ini, sizeof(ini));
    cout << "Merge Sort" << endl;
    int mergeLength = 2;
    while (mergeLength < n)
    {
      for (size_t i = 0; i < n; i += mergeLength)
      {
        if (mergeLength + i > n)
          sort(store + i, store + n);
        else
          sort(store + i, store + mergeLength + i);
      }
      if (equal(store, store + n, target, target + n  ))
      {
        mergeLength *= 2;
        for (size_t i = 0; i < n; i += mergeLength)
        {
          if (mergeLength + i > n)
            sort(store + i, store + n);
          else
            sort(store + i, store + i + mergeLength);
        }
        for (size_t i = 0; i < n; i++)
        {
          printf("%s%d", i ? " " : "", store[i]);
        }
        return 0;
      }
      mergeLength *= 2;
    }
  }
  return 0;
}