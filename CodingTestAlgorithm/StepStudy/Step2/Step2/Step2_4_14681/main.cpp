#include <bits/stdc++.h>

using namespace std;
int X, Y;
int main()
{
	cin >> X >> Y;
	if (X > 0 && Y >0)
	{
		cout << 1;
	}
	else if (X < 0 && Y>0)
	{
		cout << 2;
	}
	else if (X > 0 && Y < 0)
	{
		cout << 4;
	}
	else
	{
		cout << 3;
	}
}