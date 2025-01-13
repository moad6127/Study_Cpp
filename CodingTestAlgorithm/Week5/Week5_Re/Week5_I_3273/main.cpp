#include <bits/stdc++.h>

using namespace std;

int n, result, x, s, e;
int a[100001];
int main()
{
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
	}
	cin >> x;
	sort(a, a + n);
	e = n - 1;
	while (true)
	{
		if (s >= e)
		{
			break;
		}
		if (a[s] + a[e] == x)
		{
			result++;
			s++;
			e--;
		}
		else if (a[s] + a[e] > x)
		{
			e--;
		}
		else
		{
			s++;
		}
	}
	cout << result;

}