#include <bits/stdc++.h>

using namespace std;

int R, C, T;
pair<int, int> upA, downA;
bool upAIn;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };


int CountMap(vector<vector<int>>& map)
{
	int sum{};
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != -1)
			{
				sum += map[i][j];
			}
		}
	}
	return sum;
}

void Dust(vector<vector<int>>& map)
{
	vector<vector<int>> temp(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int sum{};
			if (map[i][j] != -1 && map[i][j])
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					{
						continue;
					}
					if (ny == upA.first && nx == upA.second)
					{
						continue;
					}
					if (ny == downA.first && nx == downA.second)
					{
						continue;
					}
					temp[ny][nx] += map[i][j] / 5;
					sum += map[i][j] / 5;
				}
				temp[i][j] += map[i][j] - sum;
			}
		}
	}
	temp[upA.first][upA.second] = -1;
	temp[downA.first][downA.second] = -1;
	map = temp;
}

void UpRotate(vector<vector<int>>& map)
{
	vector<vector<int>> temp = map;
	map[upA.first][upA.second + 1] = 0;
	//left
	for (int i = 2; i < C; i++)
	{
		map[upA.first][i] = temp[upA.first][i - 1];
	}
	//up
	for (int i = upA.first -1; i >= 0; i--)
	{
		map[i][C- 1] = temp[i + 1][C - 1];
	}
	//right
	for (int i = C - 2; i >= 0; i--)
	{
		map[0][i] = temp[0][i + 1];
	}

	//down
	for (int i = 1; i < upA.first; i++)
	{
		map[i][0] = temp[i - 1][0];
	}
	map[upA.first][upA.second] = -1;
}

void DownRotate(vector<vector<int>>& map)
{
	vector<vector<int>> temp = map;
	map[downA.first][downA.second + 1] = 0;
	//left
	for (int i = 2; i < C; i++)
	{
		map[downA.first][i] = temp[downA.first][i - 1];
	}
	//down
	for (int i = downA.first + 1; i < R; i++)
	{
		map[i][C - 1] = temp[i - 1][C - 1];
	}
	//right
	for (int i = C - 2; i >= 0; i--)
	{
		map[R - 1][i] = temp[R - 1][i + 1];
	}
	//up
	for (int i = R - 2; i >= downA.first; i--)
	{
		map[i][0] = temp[i + 1][0];
	}
	map[downA.first][downA.second] = -1;
}
int main()
{
	cin >> R >> C >> T;
	vector<vector<int>> map(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (upAIn)
				{
					downA = { i,j };
				}
				else
				{
					upA = { i,j };
					upAIn = true;
				}
			}
		}
	}
	while (true)
	{
		if (T == 0)
		{
			cout<<CountMap(map);
			break;
		}
		Dust(map);

		UpRotate(map);
		DownRotate(map);
		T--;

	}
}