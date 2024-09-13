#include <bits/stdc++.h>

using namespace std;

int n, k, temp;
int pSum[100004];
int result = -100000004;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		pSum[i] = pSum[i - 1] + temp;
	}
	for (int i = k; i <= n; i++)
	{
		result = max(result, pSum[i] - pSum[i - k]);
	}

	cout << result;
}