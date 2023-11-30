#include <bits/stdc++.h>

using namespace std;

int N;
int a[16];
int main()
{
	cin >> N;
	a[0] = 2;
	for (int i = 1; i <= 15; i++)
	{
		a[i] = a[i - 1] + (a[i - 1] - 1);
	}

	cout <<(a[N] * a[N]);
}