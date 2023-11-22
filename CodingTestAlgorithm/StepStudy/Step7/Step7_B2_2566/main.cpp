#include <bits/stdc++.h>

using namespace std;

int resultNum = -1, resultY, resultX;
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int temp{};
			cin >> temp;
			if (resultNum  < temp)
			{
				resultNum = temp;
				resultY = i;
				resultX = j;
			}
		}
	}

	cout << resultNum<<'\n';
	cout << resultY << " " << resultX;
}