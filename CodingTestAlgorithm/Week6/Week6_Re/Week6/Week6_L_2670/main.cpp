#include <bits/stdc++.h>

using namespace std;

int n;
double psum[10001], a[10001], result, b;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	b = a[0];
	result = b;

	for (int i = 1; i < n;i++)
	{
		if (a[i] > b * a[i])
		{
			b = a[i];
		}
		else
		{
			b *= a[i];
		}
		result = max(b, result);
	}
	cout << fixed << setprecision(3) << result;
}