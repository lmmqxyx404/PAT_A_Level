#include <bits/stdc++.h>
using namespace std;

int n, ans, ptn[100024], ntp[100024];

int main()
{
	int index = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ptn[i]);
		ntp[ptn[i]] = i;
	}
	while (true)
	{
		while (ntp[0] != 0)
		{
			int position0 = ntp[0];
			int positionAim = ntp[position0];
			ntp[0] = positionAim;
			ntp[position0] = position0;
			ptn[position0] = position0;
			ptn[positionAim] = 0;
			ans++;
			/*cout<<position0<<'\t'<<positionAim<<"<----"<<endl;*/
		}
		for (; index < n; index++)
		{
			/*cout<<index<<"<----index"<<endl;*/
			if (ntp[index] != index)
			{
				int position0 = ntp[0];
				int numberAim = ptn[index];
				ntp[0] = index;
				ntp[numberAim] = 0;
				ptn[0] = numberAim;
				ptn[index] = 0;
				ans++;
				break;
			}
		}
		if (index == n)
			break;
	}
	printf("%d", ans);
	return 0;
}