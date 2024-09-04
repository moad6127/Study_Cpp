#include <bits/stdc++.h>

using namespace std;

int n, x, y, result;
vector<int> check_x, check_y;
pair<int, int> a[1000004];
int x1, x2, Y1, y2, Y[1000004], X[1000004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		x += 500000;
		y += 500000;
		a[i] = { x,y };
		check_x.push_back(x);
		check_y.push_back(y);
	}
	a[n] = a[0];
	for (int i = 0; i < n; i++)
	{
		x1 = a[i].first;
		Y1 = a[i].second;
		x2 = a[i + 1].first;
		y2 = a[i + 1].second;
		if (x1 != x2)
		{
			if (x1 > x2)
			{
				swap(x1, x2);
			}
			for (int j = x1 + 1; j <= x2; j++)
			{
				X[j]++;
			}
		}
		if (Y1 != y2)
		{
			if (Y1 > y2)
			{
				swap(Y1, y2);
			}
			for (int j = Y1 + 1; j <= y2; j++)
			{
				Y[j]++;
			}
		}
	}
	for (auto e : check_x)
	{
		result = max(result, X[e]);
	}
	for (auto e : check_y)
	{
		result = max(result, Y[e]);
	}
	cout << result;
}