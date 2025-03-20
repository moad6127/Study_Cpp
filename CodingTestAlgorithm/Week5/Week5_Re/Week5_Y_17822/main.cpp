#include <bits/stdc++.h>

using namespace std;

int n, m, t, a, x, d, k;
int sum, Cirsize, result;
vector<vector<int>> Cir;


void Rot(int num, int dir, int cnt)
{
	if (dir == 0)// 시계
	{
		rotate(Cir[num - 1].rbegin(), Cir[num - 1].rbegin() + cnt, Cir[num - 1].rend());

	}
	else // 반시계
	{
		rotate(Cir[num - 1].begin(), Cir[num - 1].begin() + cnt, Cir[num - 1].end());
	}
}
//서클 체크
void printCir()
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << Cir[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int main()
{
	cin >> n >> m >> t;
	Cirsize = n * m;
	for (int i = 0; i < n;i++)
	{
		vector<int> temp;
		for (int j = 0;j < m;j++)
		{
			cin >> a;
			temp.push_back(a);
			sum += a;
		}
		Cir.push_back(temp);
	}
	for (int i = 0;i < t;i++)
	{
		set<pair<int, int>> era;
		cin >> x >> d >> k;
		for (int j = x; j <= n;j += x)
		{
			Rot(j, d, k);
		}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (Cir[i][j] == 0)
				{
					continue;
				}
				if (j + 1 < m && Cir[i][j] == Cir[i][j + 1])
				{
					era.insert({ i,j });
					era.insert({ i,j + 1 });
				}
				if (j + 1 == m && Cir[i][j] == Cir[i][0])
				{
					era.insert({ i,j });
					era.insert({ i,0 });
				}
				if (i + 1 < n && Cir[i][j] == Cir[i + 1][j])
				{
					era.insert({ i,j });
					era.insert({ i + 1,j });
				}
			}
		}
		if (era.size())
		{
			for (auto e : era)
			{
				sum -= Cir[e.first][e.second];
				Cir[e.first][e.second] = 0;
			}
			Cirsize -= era.size();
		}
		else
		{
			float avg{ (float)sum / Cirsize };
			for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < m;j++)
				{
					if (Cir[i][j] == 0)
					{
						continue;
					}
					if (Cir[i][j] > avg)
					{
						Cir[i][j] -= 1;
						sum -= 1;
					}
					else if (Cir[i][j] < avg)
					{
						Cir[i][j] += 1;
						sum += 1;
					}
				}
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			result += Cir[i][j];
		}
	}
	cout << result;
}