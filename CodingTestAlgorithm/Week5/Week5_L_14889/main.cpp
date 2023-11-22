#include <bits/stdc++.h>

using namespace std;
int N;
int input[21][21];
int result = 100000000;

int Func(vector<int>& a, vector<int>& b)
{
	int sNum{}, lNum{};
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			if (i == j)
			{
				continue;
			}
			sNum += input[a[i]][a[j]];
			lNum += input[b[i]][b[j]];
		}
	}

	return abs(sNum - lNum);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input[i][j];
		}
	}

	for (int i = 0; i < (1 << N); i++)
	{
		if (__builtin_popcount(i) != N / 2)
		{
			continue;
		}

		vector<int> start, link;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				start.push_back(j);
			}
			else
			{
				link.push_back(j);
			}
		}
		result = min(result, Func(start, link));
	}

	cout << result;
}