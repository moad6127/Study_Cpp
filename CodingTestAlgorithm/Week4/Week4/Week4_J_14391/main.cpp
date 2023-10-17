#include <bits/stdc++.h>

using namespace std;
int N, M;
int a[5][5];
int result;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			a[i][j] = s[j] - '0';
		}
	}
	for (int k = 0; k < (1 << (N * M)); k++)
	{
		int sum{};
		for (int i = 0; i < N; i++)
		{
			int check{};
			for (int j = 0; j < M; j++)
			{
				int l = i * M + j;
				if ((k & 1 << l) == 0)
				{
					check = check * 10 + a[i][j];
				}
				else
				{
					sum += check;
					check = 0;
				}
			}
			sum += check;
		}

		for (int j = 0; j < M; j++)
		{
			int check{};
			for (int i = 0; i < N; i++)
			{
				int l = i * M + j;
				if ((k & 1 << l) != 0)
				{
					check = check * 10 + a[i][j];
				}
				else
				{
					sum += check;
					check = 0;
				}
			}
			sum += check;
		}
		result = max(result, sum);
	}
	cout << result;

	return 0;
}