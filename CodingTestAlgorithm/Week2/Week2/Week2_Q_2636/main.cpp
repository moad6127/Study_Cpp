#include <bits/stdc++.h>

using namespace std;


int N, M;
int a[104][104];
int prevCheese;
int Count;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0 , 1, 0, -1 };

int Func()
{
	vector<vector<bool>> check(N, vector<bool>(M, false));
	set<pair<int, int>> removeCh{};
	queue<pair<int, int>> q{};
	q.push({ 0,0 });
	check[0][0] = true;
	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				continue;
			}
			if (a[ny][nx] == 0 && !check[ny][nx])
			{
				check[ny][nx] = true;
				q.push({ ny,nx });
			}
			else if (a[ny][nx] == 1)
			{
				removeCh.insert({ ny,nx });
			}
		}
	}
	for (auto e : removeCh)
	{
		a[e.first][e.second] = 0;
	}
	int cheeseCount{};
	cheeseCount = prevCheese - removeCh.size();
	return cheeseCount;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				prevCheese++;
			}
		}
	}


	while (true)
	{
		int CheeseCount = Func();
		if (CheeseCount == 0)
		{
			Count++;
			break;
		}
		prevCheese = CheeseCount;
		Count++;
	}

	cout << Count << '\n' << prevCheese;
}