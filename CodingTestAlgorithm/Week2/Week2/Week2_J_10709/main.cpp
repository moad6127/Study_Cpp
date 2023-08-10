#include <bits/stdc++.h>

using namespace std;

int H, W;


int main()
{
	cin >> H >> W;
	vector<vector<int>> a(H, vector<int>(W, -1));

	for (int i = 0; i < H; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < W; j++)
		{
			if (input[j] == 'c')
			{
				a[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 1; j < W; j++)
		{
			if (a[i][j] == 0)
			{
				continue;
			}
			if (a[i][j - 1] != -1)
			{
				a[i][j] = a[i][j - 1] + 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}