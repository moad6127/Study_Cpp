#include <bits/stdc++.h>

using namespace std;

long long X, Y, result = -1;
long long Z, lo, hi, mid;
int main()
{
	cin >> X >> Y;
	Z = Y * 100 / X;
	lo = 1;
	hi = 1000000001;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if ((Y + mid) * 100 / (X + mid) > Z)
		{
			result = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << result;
}