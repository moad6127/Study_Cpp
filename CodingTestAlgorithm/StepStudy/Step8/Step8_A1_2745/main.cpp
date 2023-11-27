#include <bits/stdc++.h>

using namespace std;

string N;
int B;
int result;
int main()
{
	cin >> N >> B;
	double i{(double)B};
	char temp = N.back();
	N.pop_back();
	if (temp >= 'A')
	{
		temp = temp - 'A' + 10;
	}
	else
	{
		temp = temp - '0';
	}
	result += temp;
	while (N.size())
	{
		char a{ N.back() };
		N.pop_back();
		if (a >= 'A')
		{
			a = a - 'A' + 10;
		}
		else
		{
			a = a - '0';
		}
		result += a * i;
		i *= B;
	}

	cout << result;
}