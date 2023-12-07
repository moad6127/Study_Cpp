#include <bits/stdc++.h>

using namespace std;

int N, temp, result;

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
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (Func(temp))
		{
			result++;
		}
	}
	cout << result;
}