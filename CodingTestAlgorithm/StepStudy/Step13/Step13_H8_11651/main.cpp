#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>>v;
int N, a, b;

bool Comp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), Comp);

	for (auto e : v)
	{
		cout << e.first << " " << e.second<<'\n';
	}
}