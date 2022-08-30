#include "bits/stdc++.h"
using namespace std;
int n, m, k;
unordered_map<string, int> nameToIndex;
string indexToName[333], tmpleft, tmpright;
vector<int> graph[333];
vector<pair<int, int>> result;
bool flag;
bool cmp(int asd, int qwe) {
    int realasd=stoi(indexToName[asd]);
    int realqwe=stoi(indexToName[qwe]);
    return abs(realasd)<abs(realqwe);
}
int ini(string s, int &index)
{
    if (!nameToIndex.count(s))
    {
        indexToName[index] = s;
        nameToIndex[s] = index--;
    }
    return nameToIndex[s];
}

vector<int> filter(string s) {
    vector<int> res;
    for (auto i:graph[nameToIndex[s]])
    {
        if ((s[0]=='-'&&indexToName[i][0]=='-')||(s[0]!='-'&&indexToName[i][0]!='-'))
            res.push_back(i);
    }
    return res;
}
void getResult() {
    vector<int> former=filter(tmpleft);
    vector<int> latter=filter(tmpright);
    sort(former.begin(), former.end(), cmp);
    sort(latter.begin(), latter.end(), cmp);
    for (auto i: former) {
       // cout<<"i is "<<i<<" represents "<<indexToName[i]<<endl;
        for (auto j :latter)
        {
         //   cout<<"j is "<<j<<" represents "<<indexToName[j]<<endl;
            if (find(graph[i].begin(), graph[i].end(), j)!=graph[i].end()) {
                bool tmpflag=(indexToName[i][0]=='-'&&indexToName[j][0]=='-')||(indexToName[i][0]!='-'&&indexToName[j][0]!='-');
                if (flag==tmpflag) result.push_back(make_pair(i, j));
            }
        }
    }
}
int main()
{
    freopen("Text.txt", "r", stdin);
    freopen("Text1.txt", "w", stdout);
    //    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmpleft >> tmpright;
        int u = ini(tmpleft, n);
        int v = ini(tmpright, n);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> tmpleft >> tmpright;
        result.clear();
        flag=(tmpleft[0]=='-'&&tmpright[0]=='-')||(tmpleft[0]!='-'&&tmpright[0]!='-');
        getResult();
        cout<<result.size();
        for (auto j :result)
        {
            printf("\n%04d %04d", abs(stoi(indexToName[j.first])), abs(stoi(indexToName[j.second])));
        }
        printf("%s",i==k-1?"":"\n");
    }
    return 0;
}