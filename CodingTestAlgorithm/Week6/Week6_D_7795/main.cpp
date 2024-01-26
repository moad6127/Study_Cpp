#include <bits/stdc++.h>

using namespace std;
int T, N, M;
int a[20004];
int b[20004];

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int result{};
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < M; i++)
		{
			cin >> b[i];
		}
		sort(a, a + N);
		sort(b, b + M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (a[i] > b[j])
				{
					result++;
				}
			}
		}
		cout << result<<'\n';
	}
}