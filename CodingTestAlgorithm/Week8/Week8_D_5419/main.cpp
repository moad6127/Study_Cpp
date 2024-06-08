#include <bits/stdc++.h>

using namespace std;

int T, N, x,y;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		vector<pair<int, int>> v;
		int cnt{};
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			v.push_back({ x,y });
		}
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (i == j)
				{
					continue;
				}
				if (v[i].first >= v[j].first && v[i].second <= v[j].second)
				{
					cnt++;
				}
			}
		}
		cout << cnt<<'\n';
	}

}