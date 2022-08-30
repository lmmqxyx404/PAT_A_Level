#include "bits/stdc++.h"
using namespace std;
int father[10024], N;
unordered_map<int, int> idNum, idArea, ansNum, ansArea;
set<int> storeId;
unordered_map<int, set<int>> ans;
struct family
{
	int id, memberNumber;
	double avgNum, avgArea;
};
vector<family> res;
int getFather(int a)
{
	return a == father[a] ? a : getFather(father[a]);
}
void mergeFather(int a, int s)
{
	int fa = getFather(a);
	int fs = getFather(s);
	father[max(fa,fs)]=min(fa,fs);
}
bool cmp(family asdf, family qwer)
{
	return asdf.avgArea != qwer.avgArea ? asdf.avgArea > qwer.avgArea : asdf.id < qwer.id;
}
int main()
{
	freopen("Text.txt", "r", stdin);
	freopen("Text1.txt", "w", stdout);
	ios::sync_with_stdio(false);
	iota(father,father+10024,0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmpIndex, fIndex, mIndex, childNum, tmpNum, tmpArea;
		cin >> tmpIndex >> fIndex >> mIndex >> childNum;
		storeId.insert(tmpIndex);
		if (mIndex != -1)
		{
			storeId.insert(mIndex);
			mergeFather(tmpIndex, mIndex);
		}
		if (fIndex != -1)
		{
			mergeFather(tmpIndex, fIndex);
			storeId.insert(fIndex);
		}
		for (int j = 0; j < childNum; j++)
		{
			int tmpChild;
			cin >> tmpChild;
			mergeFather(tmpIndex, tmpChild);
			storeId.insert(tmpChild);
		}
		cin >> tmpNum >> tmpArea;
		idNum.insert({tmpIndex, tmpNum});
		idArea.insert({tmpIndex, tmpArea});
	}
	for (auto i : storeId)
	{
		int iFather = getFather(i);
		ans[iFather].insert(i);
		if (idNum.count(i))
		{
			ansNum[iFather] += idNum[i];
			ansArea[iFather] += idArea[i];
		}
	}
	for (auto i : ans)
	{
		family tmp;
		tmp.id = *i.second.begin();
		tmp.memberNumber = i.second.size();
		tmp.avgNum = ansNum[getFather(tmp.id)] * 1.0 / tmp.memberNumber;
		tmp.avgArea = ansArea[getFather(tmp.id)] * 1.0 / tmp.memberNumber;
		res.push_back(tmp);
	}
	sort(res.begin(), res.end(), cmp);
	cout << res.size();
	for (auto i : res)
	{
		printf("\n%04d %d %.3f %.3f", i.id, i.memberNumber, i.avgNum, i.avgArea);
	}
	return 0;
}