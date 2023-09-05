#include <bits/stdc++.h>

using namespace std;

int K;

int a[1030];
int Count[1030];

void TreeFunc(int LeftEnd, int RightEnd, int depth)
{
	if (LeftEnd > RightEnd)
	{
		return;
	}
	if (LeftEnd == RightEnd)
	{
		Count[LeftEnd] = depth;
		return;
	}

	int Half = (LeftEnd + RightEnd) / 2;
	Count[Half] = depth;
	TreeFunc(LeftEnd, Half - 1, depth + 1);
	TreeFunc(Half + 1,RightEnd, depth + 1);
}

int main()
{
	cin >> K;
	int maxNode = pow(2, K) - 1;
	for (int i = 0; i < maxNode; i++)
	{
		cin >> a[i];
	}


	TreeFunc(0, maxNode -1, 1);

	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= maxNode; j++)
		{
			if (Count[j] == i)
			{
				cout << a[j] << " ";
			}
		}
		cout << '\n';
	}
}