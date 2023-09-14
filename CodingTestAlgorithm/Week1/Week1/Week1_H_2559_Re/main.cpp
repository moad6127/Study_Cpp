#include <bits/stdc++.h>


using namespace std;
int N, K;

int a[100004];
int sum[100004];
int result = -10000000;
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = K; i <=N; i++)
	{
		result = max(result, sum[i] - sum[i - K]);

	}
	cout << result;
}