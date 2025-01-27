#include <bits/stdc++.h>	

using namespace std;

int n, result = 987654321;
int a[21][21];
bool Check(int num)
{
	int cnt{};
	for (int i = 0; i < n;i++)
	{
		if (num & (1 << i))
		{
			cnt++;
		}
	}
	return cnt == n / 2 ? true : false;
}
int Func(vector<int>& st, vector<int>& lnk)
{
	pair<int, int> ret;
	for (int i = 0; i < n / 2;i++)
	{
		for (int j = 0;j < n / 2;j++)
		{
			if (i == j)
			{
				continue;
			}
			ret.first += a[st[i]][st[j]];
			ret.second += a[lnk[i]][lnk[j]];
		}
	}

	return abs(ret.first - ret.second);
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < (1 << n);i++)
	{
		vector<int> start;
		vector<int> link; 
		if (!Check(i))
		{
			continue;
		}
		for (int j = 0; j < n;j++)
		{
			if (i & (1 << j))
			{
				start.push_back(j);
			}
			else
			{
				link.push_back(j);
			}
		}

		result = min(result, Func(start, link));
	}
	cout << result;

}