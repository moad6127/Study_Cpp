#include <bits/stdc++.h>		

using namespace std;

long long s, c, a[1000004];
long long hi = 1000000004, low = 1, result, sum;

bool check(long long mid)
{
	long long cnt = 0;
	for (int i = 0; i < s;i++)
	{
		cnt += (a[i] / mid);
	}
	return cnt >= c;
}
int main()
{
	cin >> s >> c;
	for (int i = 0; i < s;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	while (low <= hi)
	{
		long long mid = (low + hi) / 2;
		long long sum{};
		if (check(mid))
		{
			low = mid + 1;
			result = mid;
		}
		else
		{
			hi = mid - 1;
		}

	}
	cout << sum - result * c;
}