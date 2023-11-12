#include <bits/stdc++.h>

using  namespace std;

int N;
double maxV;
double a[1004];
double sum;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		maxV = max(maxV, a[i]);
	}

	for (int i = 0; i < N; i++)
	{
		a[i] = (a[i] / maxV) * 100;
		sum += a[i];
	}

	cout << sum / N;
}