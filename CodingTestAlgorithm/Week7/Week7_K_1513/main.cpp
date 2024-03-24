#include <bits/stdc++.h>

using namespace std;

int N, M,C,temp = 1;
long long m[51][51];
const int dy[] = {0, 1};
const int dx[] = { 1,0 };
int a, b;
long long l[51][51][51];
long long Func(int x, int y,int postC,int cCnt)
{
	//cout << "x : " << x << " y : " << y << '\n';
	if (m[x][y])
	{
		if (cCnt)
		{
			if (postC)
			{
				if (m[a][b] < postC)
				{
					return 0;
				}
			}
			postC = m[x][y];
			cCnt--;
		}
		else
		{
			return 0;
		}
	}
	if (x == N && y == M)
	{
		if (cCnt == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (x<0 || x>N || y<0 || y>M)
	{
		return 0;
	}

	if (l[cCnt][x][y])
	{
		return l[cCnt][x][y];
	}

	l[cCnt][x][y] = Func(x + 1, y, postC,cCnt) + Func(x, y + 1, postC,cCnt);

	return l[cCnt][x][y];
}
int main()
{
	cin >> N >> M >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> a >> b;
		m[a][b] = temp++;
	}
	for (int i = 0; i <= C; i++)
	{
		memset(l, 0, sizeof(l));
		cout<<Func(1, 1, 0, i)<<'\n';
	}
}