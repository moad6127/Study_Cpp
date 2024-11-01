#include <bits/stdc++.h>

using namespace std;

int n;
int a[11][11];
int visited[11][11];
const int dy[] = {-1,0,1,0 };
const int dx[] = {0,-1,0,1 };
int result{987654321};


int setF(int y, int x)
{
	visited[y][x] = 1;
	int temp{ a[y][x] };
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		temp += a[ny][nx];
	}
	return temp;
}
bool Check(int y, int x)
{
	if (visited[y][x])
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
		{
			return false;
		}
		if (visited[ny][nx])
		{
			return false;
		}
	}
	return true;
}
void eraF(int y, int x)
{
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}
void Func(int nums, int sum)
{
	if (nums <= 0)
	{
		result = min(result, sum);
		return;
	}
	// 1, 1부터 n-2,n-2까지 완전 탐색
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (Check(i, j))
			{
				Func(nums - 1, sum + setF(i, j));
				eraF(i, j);
			}
		}
	}
}

int main()
{
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	//시작점은 1,1
	Func(3,0);

	cout << result;
}