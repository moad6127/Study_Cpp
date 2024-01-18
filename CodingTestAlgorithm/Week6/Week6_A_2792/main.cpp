#include <bits/stdc++.h>

using namespace std;

long long N, M, result= 1e18;
long long a[300004];

bool Check(long long mid)
{
	long long num{};
	for (int i = 0; i < M; i++)
	{
		num += a[i] / mid;
		if (a[i] % mid)
		{
			num++;
		}
	}
	return N >= num;
}

int main()
{
	cin >> N >> M;
	long long lo{ 1 };
	long long hi{};
	long long mid{};
	for (int i = 0; i < M; i++)
	{
		cin >> a[i];
		hi = max(hi, a[i]);
	}
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (Check(mid))
		{
			result = min(result, mid);
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << result;
}