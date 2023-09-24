#include <bits/stdc++.h>

using namespace std;


int N;
int result = 100000000;
int resultI;
int mp, mf, ms, mv;
int a[20][5];
map<int, vector<vector<int>>> resultMap;
int main()
{
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i < (1 << N); i++)
	{
		int checkA[5]{};
		bool check{};
		vector<int> v;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				for (int k = 0; k < 5; k++)
				{
					v.push_back(j + 1);
					checkA[k] += a[j][k];
				}
			}
		}
		if (mp <= checkA[0] && mf <= checkA[1] && ms <= checkA[2] && mv <= checkA[3])
		{
			if (result >= checkA[4])
			{
				result = checkA[4];
				resultMap[result].push_back(v);
			}
		}
	}
	if (result == 100000000)
	{
		cout << -1;
	}
	else
	{
		sort(resultMap[result].begin(), resultMap[result].end());
		cout << result << '\n';
		for (auto e : resultMap[result][0])
		{
			cout << e << " ";
		}
	}

}