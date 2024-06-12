#include <bits/stdc++.h>

using namespace std;

int N, M;
int nums[41];
int visited[42];
bool Check(string num)
{
	for (int i = 0; i < M; i++)
	{
		if (num[nums[i] - 1] - '0' != nums[i])
		{
			return false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (abs((num[i] - '0') - (i + 1)) >1)
		{
			return false;
		}
	}
	return true;
}
int Func(int here, string num)
{
	if (here >= N)
	{
		if (Check(num))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int result{};
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			result += Func(here + 1, num + char('0' + i));
			visited[i] = false;
		}
	}
	return result;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> nums[i];
	}
	cout << Func(0, "");
}