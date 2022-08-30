#include "bits/stdc++.h"
using namespace std;
int ini[104], store[104], target[104], n;
void downAdjust(int index, int n);
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
      printf("Insertion Sort\n");
      sort(store, store + i + 2);
      for (size_t i = 0; i < n; i++)
      {
        printf("%s%d", i ? " " : "", store[i]);
      }
      return 0;
    }
  }
  memcpy(store, ini, sizeof(ini));
  printf("Heap Sort\n");
  for (int i = n / 2; i >= 0; i--)
  {
    downAdjust(i, n);
  }
  for (int i = n - 1; i > 0; i--)
  {
    swap(store[i], store[0]);
    downAdjust(0, i);

    if (equal(store, store + n, target, target + n))
    {
      i--;
      swap(store[i], store[0]);
      downAdjust(0, i);
      for (size_t j = 0; j < n; j++)
      {
        printf("%s%d", j ? " " : "", store[j]);
      }
      return 0;
    }
  }
  return 0;
}

void downAdjust(int index, int n)
{
  int value = store[index];
  while (2 * index + 1 < n)
  {
    int childIndex = 2 * index + 1; //first, I must get the index of left child,but I handle with the right child node with priority.
    if (childIndex + 1 < n && store[childIndex] < store[childIndex + 1])
    {
      childIndex++;
    }
    if (store[childIndex] > value)
    {
      store[index] = store[childIndex];
      index = childIndex;
    }
    else
      break;
  }
  store[index] = value;
}