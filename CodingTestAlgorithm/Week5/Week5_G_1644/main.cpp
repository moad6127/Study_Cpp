#include <bits/stdc++.h>

using namespace std;

bool che[4000001];
int n, a[2000001], p, lo, hi, result, sum;
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if(che[i])
		{
			continue;
		}
		for (int j = 2 * i; j <= n; j += i)
		{
			che[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (!che[i])
		{
			a[p++] = i;
		}
	}

	while (true)
	{
		if (sum >= n)
		{
			sum -= a[lo++];
		}
		else if (hi == p)
		{
			break;
		}
		else sum += a[hi++];
		if (sum == n)
		{
			result;
		}
	}
	cout << result;
}