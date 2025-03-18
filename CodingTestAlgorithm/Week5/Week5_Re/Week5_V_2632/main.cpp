#include <bits/stdc++.h>

using namespace std;

int k, m, n, result;

int a[1001], b[1001];
int pSumA[2002], pSumB[2002];
map<int, int> aCnt, bCnt;

void Make(int n, int pSum[], map<int, int>& m)
{
	for (int size = 1; size <= n;size++)
	{
		for (int start = size;start <= n + size - 1;start++)
		{
			int sum = pSum[start] - pSum[start - size];
			m[sum]++;
			if (size == n)
			{
				break;
			} 
		}
	}
}

int main()
{
	cin >> k >> m >> n;
	for (int i = 1;i <= m;i++)
	{
		cin >> a[i];
		pSumA[i] = pSumA[i - 1] + a[i];
	}
	for (int i = m + 1; i <= 2 * m; i++)
	{
		pSumA[i] = pSumA[i - 1] + a[i - m];
	}

	for (int i = 1;i <= n;i++)
	{
		cin >> b[i];
		pSumB[i] = pSumB[i - 1] + b[i];
	}
	for (int i = n + 1; i <= 2 * n;i++)
	{
		pSumB[i] = pSumB[i - 1] + b[i - n];
	}
	Make(m, pSumA, aCnt);
	Make(n, pSumB, bCnt);
	result = (aCnt[k] + bCnt[k]);
	for (int i = 1; i < k;i++)
	{
		result += (aCnt[i] * bCnt[k - i]);
	}
	cout << result;
}