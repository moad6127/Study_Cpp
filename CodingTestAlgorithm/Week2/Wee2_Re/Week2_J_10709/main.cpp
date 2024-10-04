#include <bits/stdc++.h>

using namespace std;

int h, w;
string s;
int a[101][101];
int main()
{
	cin >> h >> w;
	memset(a, -1, sizeof(a));
	for (int i = 0; i < h; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'c')
			{
				a[i][j] = 0;
				for (int k = j + 1; k < s.size(); k++)
				{
					a[i][k] = a[i][j] + k - j;
				}
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}