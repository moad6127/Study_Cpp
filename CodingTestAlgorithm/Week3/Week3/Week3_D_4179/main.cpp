#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<string> a;

const int dy[4] = { -1, 1, 0 ,0 };
const int dx[4] = { 0, 0, -1, 1 };

int result = 100000000;
int main()
{
	cin >> R >> C;
	vector<vector<int>> visitedJ(R, vector<int>(C, 100000000));
	vector<vector<int>> visitedF(R, vector<int>(C, 100000000));
	queue<pair<int, int>> JQ;
	queue<pair<int, int>> FQ;
	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		a.push_back(temp);
		if (temp.find('J') != string::npos)
		{
			JQ.push({ i,temp.find('J') });
			visitedJ[i][temp.find('J')] = 1;
		}
		if (temp.find('F') != string::npos)
		{
			FQ.push({ i,temp.find('F') });
			visitedF[i][temp.find('F')] = 1;
		}
	}
	while (true)
	{
		if (JQ.empty() && FQ.empty())
		{
			break;
		}
		if (!JQ.empty())
		{
			pair<int, int> nowJ = JQ.front();
			JQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = nowJ.first + dy[i];
				int nx = nowJ.second + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				{
					continue;
				}
				if (visitedJ[ny][nx] != 100000000)
				{
					continue;
				}
				if (a[ny][nx] == '.')
				{
					JQ.push({ ny,nx });
					visitedJ[ny][nx] = visitedJ[nowJ.first][nowJ.second] + 1;
				}
			}
		}
		if (!FQ.empty())
		{
			pair<int, int> nowF = FQ.front();
			FQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = nowF.first + dy[i];
				int nx = nowF.second + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				{
					continue;
				}
				if (visitedF[ny][nx] != 100000000)
				{
					continue;
				}
				if (a[ny][nx] == '.')
				{
					FQ.push({ ny,nx });
					visitedF[ny][nx] = visitedF[nowF.first][nowF.second] + 1;
				}
			}
		}

	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == 0 || i == R - 1 || j == 0 || j == C - 1)
			{
				if (visitedJ[i][j] == 100000000)
				{
					continue;
				}
				if (visitedJ[i][j] < visitedF[i][j])
				{
					result = min(result, visitedJ[i][j]);
				}
			}
		}
	}
	if (result == 100000000)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << result;
	}

}