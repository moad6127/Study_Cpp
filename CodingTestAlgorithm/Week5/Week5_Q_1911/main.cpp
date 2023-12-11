#include <bits/stdc++.h>

using namespace std;

int N, L, idx,b;
int result;
int main()
{
	cin >> N >> L;
	vector<pair<int, int>>a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++)
	{
		if (a[i].second <= idx)
		{
			continue;
		}
		if (idx < a[i].first)
		{
			b = (a[i].second - a[i].first) / L + ((a[i].second - a[i].first) % L ? 1 : 0);
			idx = a[i].first + b * L;
 		}
		else
		{
			b = (a[i].second - idx) / L + ((a[i].second - idx) % L ? 1 : 0);
			idx = idx + b * L;
		}
		result += b;
	}
	cout << result;
}