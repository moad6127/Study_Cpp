#include <bits/stdc++.h>	
using namespace	std;

long long x, y, z;
long long low, hi, result = -1;
int main()
{
	cin >> x >> y;
	z = y * 100 / x;
	low = 1;
	hi = 1000000000;
	while (low <= hi)
	{
		long long mid = (low + hi) / 2;
		if ((y + mid) * 100 / (x + mid) > z)
		{
			result = mid;
			hi = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << result;
}