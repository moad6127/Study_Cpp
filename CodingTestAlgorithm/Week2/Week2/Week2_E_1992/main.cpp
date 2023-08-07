#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> a;
string Func(int y, int x, int size)
{
	if (size == 1)
	{
		return string(1, a[y][x]);
	}
	char checkChar{ a[y][x] };
	string result = "";
	for (int i = y; i <y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (checkChar != a[i][j])
			{
				result += '(';
				result += Func(y, x, size / 2);
				result += Func(y, x + size / 2, size / 2);
				result += Func(y + size / 2, x, size / 2);
				result += Func(y + size / 2, x + size / 2, size / 2);
				result += ')';
				return result;
			}
		}
	}

	return string(1, a[y][x]);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp{};
		cin >> temp;
		a.push_back(temp);
	}

	cout<<Func(0, 0,N);
}