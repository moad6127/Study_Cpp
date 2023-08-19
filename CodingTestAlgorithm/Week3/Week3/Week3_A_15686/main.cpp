#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[54][54];
vector<pair<int, int>> HL;
vector<pair<int, int>> CL;
int result = 100000000;

void DistanceCheck(vector<pair<int, int>>& SaveCh)
{
	int DisSum{};
	for (int i = 0; i < HL.size(); i++)
	{
		int minNum = 100000000;
		for (int j = 0; j < SaveCh.size(); j++)
		{
			int dis = (abs(HL[i].first - SaveCh[j].first) + abs(HL[i].second - SaveCh[j].second));
			minNum = min(minNum, dis);
		}
		DisSum += minNum;
	}
	result = min(result, DisSum);
}

void Func(int num, vector<pair<int, int>>& SaveCh)
{
	if (SaveCh.size() == M)
	{
		DistanceCheck(SaveCh);
		return;
	}
	for (int i = num + 1; i < CL.size(); i++)
	{
		SaveCh.push_back(CL[i]);
		Func(i, SaveCh);
		SaveCh.pop_back();
	}
}
int main()
{
	cin >> N >> M;
	vector<pair<int, int>> SC;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				HL.push_back({ i,j });
			}
			if (a[i][j] == 2)
			{
				CL.push_back({ i,j });
			}
		}
	}
	Func(-1, SC);
	cout << result;
}