#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int N, a, b;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e.first << " " << e.second << '\n';
	}
}