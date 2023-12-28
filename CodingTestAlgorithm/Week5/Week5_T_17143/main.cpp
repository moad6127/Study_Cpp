#include <bits/stdc++.h>

using namespace std;

int R, C, M;
struct Shark
{
	int y, x, s, dir, z, death;
}a[101*101];
int r, c, s, d, z;
const int dx[] = { 0 , 0 ,1, -1 };
const int dy[] = { -1,1,0,0 };
int shark[104][104], temp[104][104];
int result;
int main()
{
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
		a[i].y--; a[i].x--; a[i].dir--;

		if (a[i].dir <= 1)
		{
			a[i].s %= (2 * (R - 1));
		}
		else
		{
			a[i].s %= (2 * (C - 1));
		}

		shark[a[i].y][a[i].x] = i;
	}

	for (int t = 0; t < C; t++)
	{
		for (int k = 0; k < R ; k++)
		{
			if (shark[k][t])
			{
				a[shark[k][t]].death = 1;
				result += a[shark[k][t]].z;
				shark[k][t] = 0;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= M; i++)
		{
			if (a[i].death)
			{
				continue;
			}
			int y = a[i].y;
			int x = a[i].x;
			int s = a[i].s;
			int d = a[i].dir;
			int ny{}, nx{};
			while (1)
			{
				ny = y + s * dy[d];
				nx = x + s * dx[d];
				if (nx < C && ny < R && ny >= 0 && nx >= 0)
				{
					break;
				}
				if (d <= 1)
				{
					if (ny < 0)
					{
						s -= y;
						y = 0;
					}
					else
					{
						s -= R - 1 - y;
						y = R - 1;
					}
				}
				else
				{
					if (nx < 0)
					{
						s -= x;
						x = 0;
					}
					else
					{
						s -= C - 1 - x;
						x = C - 1;
					}
				}
				d ^= 1;
			}
			if (temp[ny][nx])
			{
				if (a[temp[ny][nx]].z < a[i].z)
				{
					a[temp[ny][nx]].death = 1;
					temp[ny][nx] = i;
				}
				else
				{
					a[i].death = 1;
				}
			}
			else
			{
				temp[ny][nx] = i;
			}

			a[i].y = ny;
			a[i].x = nx;
			a[i].dir = d;
		}
		memcpy(shark, temp, sizeof(temp));
	}

	cout << result;
}