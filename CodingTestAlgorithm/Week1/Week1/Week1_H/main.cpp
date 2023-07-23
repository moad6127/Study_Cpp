#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num{}, K{};
	cin >> num>>K;
	vector<int> pList(num + 1, 0);
	int Max{ -10000 };
	for (int i = 1; i <= num; i++)
	{
		int a{};
		cin >> a;
		pList[i] = pList[i - 1] + a;
	}
	for (int i = K; i <= num; i++)
	{
		Max = max(pList[i] - pList[i - K], Max);
	}
	cout << Max;
}