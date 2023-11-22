#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[103][103];

int main()
{
	cin >> N >> M;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int temp{};
				cin >> temp;
				a[i][j] += temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}