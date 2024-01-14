
#include <bits/stdc++.h>

using namespace std;

int n;
int result, a, b, l, r;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	l = v[0].first;
	r = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (r < v[i].first)
		{
			result += (r - l);
			l = v[i].first;
			r = v[i].second;
		}
		else if (v[i].first <= r && v[i].second >= r)
		{
			r = v[i].second;
		}
	}
	result += r - l;
	cout << result;

}