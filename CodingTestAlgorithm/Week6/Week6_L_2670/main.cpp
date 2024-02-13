#include <bits/stdc++.h>

using namespace std;

int N;
double a[10004];
double pMul[10004], b, result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	b = a[0];
	result = b;
	for (int i = 1; i < N; i++)
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
	printf("%.3lf", result);
}