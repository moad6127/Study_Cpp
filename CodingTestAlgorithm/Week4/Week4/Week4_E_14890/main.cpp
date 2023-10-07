#include <bits/stdc++.h>

using namespace std;

int N, L;
int a[104][104], b[104][104];
int result;

void Func(int a[104][104])
{
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		int j{};
		for (j = 0; j < N - 1; j++)
		{
			if (a[i][j] == a[i][j + 1])
			{
				cnt++;
			}
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= L)
			{
				cnt = 1;
			}
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0)
			{
				cnt = -L + 1;
			}
			else
			{
				break;
			}
		}
		if (j == N - 1 && cnt >= 0)
		{
			result++;
		}
	}
}

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	Func(a);
	Func(b);
	cout << result << '\n';

}