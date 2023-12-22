#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[104];
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
		if (result == M)
		{
			break;
		}
		for (int j = i + 1; j < N; j++)
		{
			if (result == M)
			{
				break;
			}
			for (int k = j + 1; k < N; k++)
			{
				if (result == M)
				{
					break;
				}
				if (a[i] + a[j] + a[k] <= M)
				{
					result = max(result, a[i] + a[j] + a[k]);
				}
			}
		}
	}
	cout << result;
}