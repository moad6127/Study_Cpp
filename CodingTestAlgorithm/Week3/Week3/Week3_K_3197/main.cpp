#include <bits/stdc++.h>


using namespace std;

int R, C;
char a[1504][1504];
vector<pair<int, int>> LL;
int visited_S[1504][1504];
int visited_W[1504][1504];
int result;
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0 ,0 ,-1, 1 };
int SY, SX;
queue<pair<int, int>> SQ;
queue<pair<int, int>> SQ_Temp;
queue<pair<int, int>> WQ;
queue<pair<int, int>> WQ_Temp;

void Clear (queue<pair<int, int>>& Q)
{
	queue<pair<int, int>> q;
	swap(Q, q);
}

bool SBFS()
{
	while (SQ.size())
	{
		pair<int,int> now = SQ.front();
		SQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			{
				continue;
			}
			if (visited_S[ny][nx])
			{
				continue;
			}
			visited_S[ny][nx] = 1;
			if (a[ny][nx] == '.')
			{
				SQ.push({ ny,nx });
			}
			if (a[ny][nx] == 'X')
			{
				SQ_Temp.push({ ny,nx });
			}
			if (a[ny][nx] == 'L')
			{
				return true;
			}
		}
	}
	return false;
}

void WBFS()
{
	while (WQ.size())
	{
		pair<int, int> now = WQ.front();
		WQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			{
				continue;
			}
			if (visited_W[ny][nx])
			{
				continue;
			}
			if (a[ny][nx] == 'X')
			{
				WQ_Temp.push({ ny,nx });
				visited_W[ny][nx] = 1;
				a[ny][nx] = '.';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++)
		{
			a[i][j] = temp[j];
			if (temp[j] == 'L')
			{
				SY = i;
				SX = j;
			}
			if (temp[j] == '.' || temp[j] == 'L')
			{
				WQ.push({ i,j });
			}
		}
	}
	SQ.push({ SY,SX });
	visited_S[SY][SX] = 1;

	while (true)
	{
		if (SBFS())
		{
			break;
		}
		WBFS();
		SQ = SQ_Temp;
		WQ = WQ_Temp;
		Clear(SQ_Temp);
		Clear(WQ_Temp);

		result++;

	}
	cout << result;

	return 0;
}