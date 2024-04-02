#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A(10,vector<int>(10,0));
int result = 100000;

bool check(int startX, int startY, int size, vector<vector<int>>& a)
{
	for (int i = startY; i < startY + size; i++)
	{
		for (int j = startX; j < startX + size; j++)
		{
			if (a[i][j] != 1)
			{
				return false;
			}
		}
	}
	return true;
}
void zFunc(int startX, int startY, int size, vector<vector<int>>& a)
{
	for (int i = startY; i < startY + size; i++)
	{
		for (int j = startX; j < startX + size; j++)
		{
			a[i][j] = 0;
		}
	}
}
bool checkNum(vector<vector<int>>& a)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}
void fullTemp()
{
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> A[i][j];
		}
	}
	vector<int> pSize{1, 2, 3, 4, 5};
	do
	{
		vector<vector<int>> b(A.begin(), A.end());
		int temp{};
		for (int size = 0; size < pSize.size(); size++)
		{
			int maxCnt{ 5 };
			for (int i = 0; i <= 10 - pSize[size]; i++)
			{
				for (int j = 0; j <= 10 - pSize[size]; j++)
				{
					if (b[i][j] == 1)
					{
						if (maxCnt && check(j, i, pSize[size],b))
						{
							zFunc(j, i, pSize[size],b);
							temp++;
							maxCnt--;
						}
					}
				}
			}
		}
		if (checkNum(b))
		{
			result = min(result, temp);
		}
		

	} while (next_permutation(pSize.begin(), pSize.end()));
	if (result == 100000)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
}