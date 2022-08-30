#include "bits/stdc++.h"
using namespace std;
unordered_map<string, set<string>> authorToId, yearToId, titleToId, publisherToId;
map<string, string> idToKeyword;
int n, m, tmp;
string id, title, author, year, keyword, publisher, query;
set<string> ans;

void Process(unordered_map<string, set<string>> &index, string &query)
{
  if (index.count(query))
  {
    ans = index[query];
    for (auto j : ans)
    {
      cout << j << endl;
    }
  }
  else
  {
    printf("Not Found\n");
  }
}
int main()
{
  cin >> n;
  getchar();
  for (size_t i = 0; i < n; i++)
  {
    getline(cin, id);
    getline(cin, title);
    getline(cin, author);
    getline(cin, keyword);
    getline(cin, publisher);
    getline(cin, year);
    titleToId[title].insert(id);
    authorToId[author].insert(id);
    idToKeyword[id] = keyword;
    publisherToId[publisher].insert(id);
    yearToId[year].insert(id);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    scanf("%d: ", &tmp);
    getline(cin, query);
    printf("%d: %s\n", tmp, query.c_str());
    ans.clear();
    switch (tmp)
    {
    case 3:
      for (auto j : idToKeyword)
      {
        if (j.second.find(query) != string::npos)
        {
          ans.insert(j.first);
        }
      }
      if (ans.size())
      {
        for (auto j : ans)
        {
          cout << j << endl;
        }
      }
      else
      {
        printf("Not Found\n");
      }
      break;
    case 2:
      Process(authorToId, query);
      break;
    case 1:
      Process(titleToId, query);
      break;
    case 4:
      Process(publisherToId, query);
      break;
    case 5:
      Process(yearToId, query);
      break;
    default:
      printf("\nError\n");
      break;
    }
  }
  return 0;
}