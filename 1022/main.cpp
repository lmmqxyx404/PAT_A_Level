#include "bits/stdc++.h"
using namespace std;
unordered_map<string, set<string>> authorToId, yearToId, titleToId, publisherToId;
map<string, string> idToKeyword;
int n, m, tmp;
string id, title, author, year, keyword, publisher, query;
set<string> ans;

// watch out to use & properly anytime
void Process(unordered_map<string, set<string>> &index, string &query)
{
  if (index.count(query))
  {
    for (auto i = index[query].begin(); i != index[query].end(); i++)
    {
      printf("%s\n", (*i).c_str());
    }
  }
  else
  {
    printf("Not Found\n");
  }
}
int main()
{
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++)
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
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d: ", &tmp);
    getline(cin, query);
    printf("%d: %s\n", tmp, query.c_str());
    switch (tmp)
    {
    case 3:
      ans.clear();
      for (auto j : idToKeyword)
      {
        if (j.second.find(query) != string::npos)
        {
          ans.insert(j.first);
        }
      }
      if (ans.size())
      {
        for (auto k = ans.begin(); k != ans.end(); k++)
        {
          printf("%s\n", (*k).c_str());
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