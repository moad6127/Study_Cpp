#include <bits/stdc++.h>

using namespace std;

int N;
char a[70][70];
string result;


string Func(int sy, int sx, int num)
{
	char checkCh = a[sy][sx];
	if (num == 1)
	{
		return string{ checkCh };
	}
	string temp{};
	for (int i = sy; i < sy + num; i++)
	{
		for (int j = sx; j < sx + num; j++)
		{
			if (checkCh != a[i][j])
			{
				temp += "(";
				temp += Func(sy, sx, num / 2);
				temp += Func(sy, sx + num / 2, num / 2);
				temp += Func(sy + num / 2, sx, num / 2);
				temp += Func(sy + num / 2, sx + num / 2, num / 2);
				temp += ")";
				return temp;
			}
		}
	}
	return string{ checkCh };
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			a[i][j] = temp[j];
		}
	}
	result = Func(0, 0, N);
	cout << result;

}