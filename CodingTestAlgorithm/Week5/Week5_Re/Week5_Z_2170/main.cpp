#include <bits/stdc++.h>

using namespace std;

int n, x, y;
int result, st, ed;
vector<pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	st = v[0].first;
	ed = v[0].second;
	for (int i = 1; i < n;i++)
	{
		if (v[i].first > ed)
		{
			result += ed - st;
			st = v[i].first;
			ed = v[i].second;
		}
		else if(v[i].first <= ed && v[i].second >= ed)
		{
			ed = v[i].second;
		}
	}
	result += ed - st;
	cout << result;
}