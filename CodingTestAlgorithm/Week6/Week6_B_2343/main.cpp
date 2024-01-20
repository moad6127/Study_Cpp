#include <bits/stdc++.h>

using namespace std;
int result = 987654321;
int N, M, lo, hi, sum, mx;
int a[100004];

bool check(int mid)
{
	if (mx > mid)
	{
		return false;
	}
	int count{};
	int temp{ mid };
	for (int i = 0; i < N; i++)
	{
		if (mid - a[i] < 0)
		{
			mid = temp;
			count++;
		}
		mid -= a[i];
	}
	if (mid != temp)
	{
		count++;
	}
	return count <= M;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	lo = 0;
	hi = sum;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid - 1;
			result = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << result;
}