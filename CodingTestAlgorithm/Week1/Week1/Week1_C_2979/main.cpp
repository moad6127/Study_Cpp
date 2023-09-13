#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int checkT[104];
int result;
int main()
{
	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++)
	{
		int in{}, out{};
		cin >> in >> out;
		for (int j = in; j < out; j++)
		{
			checkT[j]++;
		}
	}

	for (auto e : checkT)
	{
		if (e == 1)
		{
			result += (A);
		}
		else if (e == 2)
		{
			result += (B * 2);
		}
		else if (e == 3)
		{
			result += (C * 3);
		}
	}
	cout << result;
}