#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[15004];
int s, e, result;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	e = n - 1;
	while (true)
	{
		if (s >= e)
		{
			break;
		}
		int sum = a[s] + a[e];
		if (sum > m)
		{
			e--;
		}
		else if (sum < m)
		{
			s++;
		}
		else
		{
			result++;
			s++;
			e--;
		}
	}
	cout << result;
}