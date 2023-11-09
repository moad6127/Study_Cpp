#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> PList;
int result;

bool CheckPrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void CheckList()
{
	for (int i = 2; i <= N; i++)
	{
		if (CheckPrime(i))
		{
			PList.push_back(i);
		}
	}
}
int main()
{
	cin >> N;
	CheckList();

	for (int i = 0; i < PList.size(); i++)
	{
		int sum{PList[i]};
		if (sum == N)
		{
			result++;
			break;
		}
		for (int j = i + 1; j < PList.size(); j++)
		{
			sum += PList[j];
			if (sum > N)
			{
				break;
			}
			else if (sum == N)
			{
				result++;
				break;
			}
		}
	}
	cout << result;
}