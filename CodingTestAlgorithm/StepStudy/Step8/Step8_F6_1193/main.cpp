#include <bits/stdc++.h>

using namespace std;

int N;
int num{ 1 };
int downNum{};
int upNum{};

int main()
{
	cin >> N;
	N--;

	while (true)
	{
		if (N < num)
		{
			break;
		}
		N -= num;
		num++;
	}

	if (num % 2)
	{
		downNum = N + 1;
		upNum = num - N;
	}
	else
	{
		upNum = N + 1;
		downNum = num - N;
	}

	cout << upNum<<"/" << downNum;

}