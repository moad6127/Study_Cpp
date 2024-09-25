#include <bits/stdc++.h>

using namespace std;

vector<string> a;
int si;
string s;

string Func(int size, int startY, int startX)
{
	if (size == 1)
	{
		return string(1, a[startY][startX]);
	}
	char Comp = a[startY][startX];
	string result;
	for (int i = startY; i < startY + size; i++)
	{
		for (int j = startX; j < startX + size; j++)
		{
			if (Comp != a[i][j])
			{
				result.push_back('(');
				result += Func(size / 2, startY, startX);
				result += Func(size / 2, startY, startX + size / 2);
				result += Func(size / 2, startY + size / 2, startX);
				result += Func(size / 2, startY + size / 2, startX + size / 2);
				result.push_back(')');
				return result;
			}
		}
	}
	result.push_back(Comp);
	return result;
}
int main()
{
	cin >> si;
	for (int i = 0; i < si; i++)
	{
		cin >> s;
		a.push_back(s);
	}
	cout << Func(si, 0, 0);
}