#include <bits/stdc++.h>

using namespace std;

int n, m, mx, low, hi;
int a[100004], result;

bool Check(int mid)
{
	int cnt = 1;
	int temp = mid;
	for (int i = 0; i < n;i++)
	{
		if (mid - a[i] < 0)
		{
			mid = temp;
			cnt++;
		}
		mid -= a[i];
	}
	return cnt <= m;
}
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		mx = max(a[i], mx);
	}
	low = mx;
	hi = 1000000004;
	while (low <= hi)
	{
		int mid = (low + hi) / 2;
		if (Check(mid))
		{
			hi = mid - 1;
			result = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << result;
}