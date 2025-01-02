#include <bits/stdc++.h>

using namespace std;

int n, a, b, result;
vector<pair<int, int>> v;
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	result = v[0].first + v[0].second;
	for (int i = 1; i < n;i++)
	{
		result = max(result, v[i].first);
		result += v[i].second;
	}
	cout << result;

}