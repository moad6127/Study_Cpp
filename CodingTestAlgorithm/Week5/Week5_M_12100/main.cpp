#include <bits/stdc++.h>

using namespace std;

int N;
int result;

void CountingFunc(vector<vector<int>>& map)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result = max(result, map[i][j]);
		}
	}

	
}
void Move(vector<vector<int>>& map)
{
	vector<vector<int>> temp(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		int c = -1, d = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) continue;
			if (d && map[i][j] == temp[i][c]) temp[i][c] *= 2, d = 0;
			else temp[i][++c] = map[i][j], d = 1;
		}
		for (c++; c < N; c++) temp[i][c] = 0;
	}
	map = temp;
}
void Rotate(vector<vector<int>>& map)
{
	vector<vector<int>> temp(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[N - j - 1][i];
		}
	}
	map = temp;
}
void MoveFun(int count, vector<vector<int>> map)
{
	if (count == 5)
	{
		CountingFunc(map);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> temp;
		temp = map;
		Move(temp);
		MoveFun(count + 1, temp);
		Rotate(map);
	}
}

int main()
{
	cin >> N;
	vector<vector<int>> a(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}

	MoveFun(0, a);

	cout << result;
}