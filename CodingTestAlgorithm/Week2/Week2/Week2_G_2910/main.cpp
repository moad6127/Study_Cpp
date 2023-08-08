#include <bits/stdc++.h>


using namespace std;

int N, C;
map<int, int> m1, m2;

bool comp(pair<int, int> a, pair<int, int>b)
{
	if (a.second == b.second)
	{
		return m2[a.first] < m2[b.first];
	}
	return a.second > b.second;
}

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		m1[temp]++;
		if (m2[temp] == 0)
		{
			m2[temp] = i + 1;
		}
	}
	vector<pair<int, int>> c(m1.begin(), m1.end());
	sort(c.begin(), c.end(),comp);
	for (auto e : c)
	{
		for (int i = 0; i < e.second; i++)
		{
			cout << e.first << " ";
		}
	}
}