#include <bits/stdc++.h>

using namespace std;

int T, K, num,dirNum;
bool dir;
char leftNum, rightNum;
int result;
vector<string> v;

void Rotate(int _num, bool _dir)
{
	if (_dir)
	{
		rotate(v[_num].rbegin(), v[_num].rbegin() + 1, v[_num].rend());
	}
	else
	{
		rotate(v[_num].begin(), v[_num].begin() + 1, v[_num].end());
	}
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> K;
	queue<pair<int,bool>> q;
	for (int i = 0; i < K; i++)
	{
		cin >> num >> dirNum;
		num--;
		if (dirNum == -1)
		{
			dir = 0;
		}
		else
		{
			dir = 1;
		}
		leftNum = v[num][6];
		rightNum = v[num][2];
		Rotate(num, dir);
		if (num - 1 >= 0 && leftNum != v[num - 1][2])
		{
			q.push({ num - 1, !dir});
		}
		if (num + 1 < T && rightNum != v[num + 1][6])
		{
			q.push({ num + 1, !dir });
		}
		while (q.size())
		{
			pair<int, int> now = q.front();
			q.pop();
			leftNum = v[now.first][6];
			rightNum = v[now.first][2];
			Rotate(now.first, now.second);
			if (now.first < num)
			{
				if (now.first - 1 >= 0 && leftNum != v[now.first - 1][2])
				{
					q.push({ now.first - 1,!now.second });
				}
			}
			else
			{
				if (now.first + 1 < T && rightNum != v[now.first + 1][6])
				{
					q.push({ now.first + 1, !now.second });
				}
			}
		}
	}
	for (int i = 0; i < T; i++)
	{
		if (v[i][0] == '1')
		{
			result++;
		}
	}
	cout << result;
}