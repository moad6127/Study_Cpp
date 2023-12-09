#include <bits/stdc++.h>

using namespace std;

int M, N;
int minResult = 987654321;
int sumResult;

bool Func(int temp)
{
	if (temp < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= temp; i++)
	{
		if (temp % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (Func(i))
		{
			sumResult += i;
			minResult = min(minResult, i);
		}
	}

	if (sumResult == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sumResult << '\n';
		cout << minResult << '\n';
	}
}