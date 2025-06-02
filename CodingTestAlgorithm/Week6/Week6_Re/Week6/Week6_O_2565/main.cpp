#include <bits/stdc++.h>

using namespace std;

int n, a, b, len, lis[504];
vector<pair<int, int>> ls;
int main()
{
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> a >> b;
		ls.push_back({ a,b });
	}
	sort(ls.begin(), ls.end());
	for (int i = 0;i < ls.size();i++)
	{
		auto itr = lower_bound(lis, lis + len, ls[i].second);
		if (*itr == 0)
		{
			len++;
		}
		*itr = ls[i].second;
	}
	cout << n - len;
}