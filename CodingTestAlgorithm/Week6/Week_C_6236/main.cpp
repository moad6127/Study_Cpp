#include <bits/stdc++.h>

using namespace std;

int N, M, mx, lo, hi, result;
int a[100004];
bool check(int mid)
{
	int count = 1;
	int temp = mid;
	for (int i = 0; i < N; i++)
	{
		if (mid - a[i] < 0)
		{
			mid = temp;
			count++;
		}
		mid -= a[i];
	}
	return count <= M;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	lo = mx;
	hi = 9876543210;
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