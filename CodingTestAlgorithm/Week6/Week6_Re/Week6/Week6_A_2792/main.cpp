#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long a[300001], result = 1e18;

bool Check(long long mid)
{
	long long num = 0;
	for (int i = 0; i < m;i++)
	{
		num += a[i] / mid;
		if (a[i] % mid)
		{
			num++;
		}
	}
	return n >= num;
}

int main()
{
	cin >> n >> m;
	long long low = 1;
	long long hi = 0;
	long long mid;

	for (int i = 0; i < m;i++)
	{
		cin >> a[i];
		hi = max(hi, a[i]);
	}
	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (Check(mid))
		{
			result = min(result, mid);
			hi = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << result;

}