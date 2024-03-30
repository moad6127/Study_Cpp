#include <bits/stdc++.h>

using namespace std;


int N, M, K, x, y, z;
int A[11][11],C[11][11];
vector<int> T[11][11];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int result;
void springSum()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (T[i][j].empty())
			{
				continue;
			}
			sort(T[i][j].begin(), T[i][j].end());
			int dieCnt{};
			vector<int>temp;
			for (auto e : T[i][j])
			{
				if (C[i][j] >= e)
				{
					C[i][j] -= e;
					temp.push_back(e + 1);
				}
				else
				{
					dieCnt += e / 2;
				}
			}
			T[i][j] = temp;
			C[i][j] += dieCnt;
		}
	}
}
void fall()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (T[i][j].empty())
			{
				continue;
			}
			for (auto e : T[i][j])
			{
				if (e % 5 == 0)
				{
					for (int k = 0; k < 8; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						{
							continue;
						}
						T[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}
void win()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C[i][j] += A[i][j];
		}
	}
}
int main()
{
	cin >> N >> M >> K;

	fill(&C[0][0], &C[0][0] + 11 * 11, 5);

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;
		T[--x][--y].push_back(z);
	}
	for (int i = 0; i < K; i++)
	{
		springSum();
		fall();
		win();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result += T[i][j].size();
		}
	}
	cout << result;
}