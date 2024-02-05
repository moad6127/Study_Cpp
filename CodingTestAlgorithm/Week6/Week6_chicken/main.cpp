#include <bits/stdc++.h>

using namespace std;

long long S, C, lo = 1, hi = 1000000001, result, sum;

bool check(long long mid,vector<long long>& a)
{
	long long num{};
	for (int i = 0; i < S; i++)
	{
		num += a[i] / mid;
	}
	return num >= C;
}
int main()
{
	cin >> S >> C;
	vector<long long> a(S);
	for (int i = 0; i < S; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	long long mid{};
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid,a))
		{
			result = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	cout << sum - (result * C);
}