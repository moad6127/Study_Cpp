#include <bits/stdc++.h>

using namespace std;

int n, l, st, ed, idx, result , temp;
vector<pair<int, int>> v;
int main()
{
	cin >> n >> l;
	for (int i = 0;i < n;i++)
	{
		cin >> st >> ed;
		v.push_back({ st,ed });
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++)
	{
		if (v[i].second <= idx)
		{
			continue;
		}
		if (idx < v[i].first)
		{
			temp = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
			idx = v[i].first + temp * l;
		}
		else
		{
			temp = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0);
			idx = idx + temp * l;
		}
		result += temp;
	}
	cout << result;
}