#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100004];
int low, hi, result, sum, mx;

bool Check(int mid)
{
	if (mx > mid)
	{
		return false;
	}
	int temp = mid;
	int cnt = 0;
	for (int i = 0;i < n;i++)
	{
		if (mid - a[i] < 0)
		{
			mid = temp;
			cnt++;
		}
		mid -= a[i];
	}
	if (mid != temp)
	{
		cnt++;
	}
	return cnt <= m;
}
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	low = 0;
	hi = sum;
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