#include <bits/stdc++.h>

using namespace std;
int N, M;
int a[15004];
int result;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] + a[j] == M)
			{
				result++;
			}
		}
	}
	cout << result;
}