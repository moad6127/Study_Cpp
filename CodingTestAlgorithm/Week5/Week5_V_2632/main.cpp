#include <bits/stdc++.h>

using namespace std;

int K, M, N;
int a[1001], b[1001],psum_a[2002],psum_b[2002];
int result;
map<int, int> aCnt, bCnt;

void Make(int n, int psum[], map<int, int>& mp)
{
	for (int inte = 1; inte <= n; inte++)
	{
		for (int start = inte; start <= n + inte - 1; start++)
		{
			int sum = psum[start] - psum[start - inte];
			mp[sum]++;
			if (inte == n)
			{
				break;
			}
		}
	}
}
int main()
{
	cin >> K >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];
	}
	for (int i = M + 1; i <= 2 * M; i++)
	{
		psum_a[i] = psum_a[i - 1] + a[i - M];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];
	}
	for (int i = N + 1; i <= 2 * N; i++)
	{
		psum_b[i] = psum_b[i - 1] + b[i - N];
	}
	Make(M, psum_a, aCnt);
	Make(N, psum_b, bCnt);
	result = (aCnt[K] + bCnt[K]);
	for (int i = 1; i < K; i++)
	{
		result += (aCnt[i] * bCnt[K - i]);
	}
	cout << result;
}