#include <bits/stdc++.h>

using namespace std;

int N;
int minNum{ 1000004 }, maxNum{ -1000004 };
int temp;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		minNum = min(minNum, temp);
		maxNum = max(maxNum, temp);
	}
	cout << minNum << " " << maxNum;
}