#include "bits/stdc++.h"
using namespace std;
string ini, match;
unordered_map<char, bool> instruct;
int main(){
  ios::sync_with_stdio(false);
  cin >> ini >> match;
  for (auto i : match)
    instruct[toupper(i)] = true;
  for (auto i : ini)
    if (!instruct[toupper(i)])
      printf("%c", toupper(i)),instruct[toupper(i)] = true;   
  return 0;
}