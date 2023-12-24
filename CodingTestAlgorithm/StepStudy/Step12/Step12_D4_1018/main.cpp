#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> a;
int result = 987654321;
void Func(int y, int x)
{
	int WSum{};
	int BSum{};

	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j <x + 8; j++)
		{

		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			Func(i, j);
		}
	}
}