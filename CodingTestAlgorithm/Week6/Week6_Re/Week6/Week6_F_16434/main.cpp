#include <bits/stdc++.h>

using namespace std;

long long n, Hatk, t[130004], a[130004], h[130004], lo, hi, result;

bool Check(long long mid)
{
	long long mxHP = mid;
	long long init_attak = Hatk;
	for (int i = 0;i < n;i++)
	{
		if (t[i] == 2)
		{
			mid = min(mxHP, mid + h[i]);
			init_attak += a[i];
		}
		else
		{
			long long cnt = h[i] / init_attak + (h[i] % init_attak ? 1 : 0);
			mid -= (cnt - 1) * a[i];
		}
		if (mid <= 0)
		{
			return false;	
		}
	}
	return true;
}

int main()
{
	cin >> n >> Hatk;
	for (int i = 0;i < n;i++)
	{
		cin >> t[i] >> a[i] >> h[i];
	}
	lo = 1;
	hi = 1e18 + 4;
	while (lo <= hi)
	{
		long long mid = (lo + hi) / 2;
		if (Check(mid))
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