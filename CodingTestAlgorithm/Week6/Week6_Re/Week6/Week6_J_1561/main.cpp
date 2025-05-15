#include <bits/stdc++.h>

using namespace std;

long long n, m, low, hi = 60000000004, mid;
long long a[10004], result;

bool Check(long long mid)
{
	long long temp{ m };
	for (long long i = 0; i < m;i++)
	{
		temp += mid / a[i];
	}
	return temp >= n;
}
int main()
{
	cin >> n >> m;
	for (long long i = 0;i < m;i++)
	{
		cin >> a[i];
	}
	if (n <= m)
	{
		cout << n;
		return 0;
	}
	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (Check(mid))
		{
			result = mid;
			hi = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	long long temp{ m };
	for (long long i = 0;i < m;i++)
	{
		temp += ((result - 1) / a[i]);
	}
	for (long long i = 0;i < m;i++)
	{
		if (result % a[i] == 0)
		{
			temp++;
		}
		if (temp == n)
		{
			cout << i + 1;
			return 0;
		}
	}
}