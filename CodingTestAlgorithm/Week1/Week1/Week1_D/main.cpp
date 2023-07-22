/*
int main()
{

	string input{};
	cin >> input;
	int start{};
	int back = input.length() - 1;

	while (true)
	{
		if (start > back)
		{
			break;
		}

		if (input[start] != input[back])
		{
			cout << 0;
			return 0;
		}
		start++;
		back--;
	}
	cout << 1;
	return 0;
}

*/

#include <bits/stdc++.h>

using namespace std;


int main()
{
	string input{}, temp{};
	cin >> input;
	temp = input;

	reverse(input.begin(), input.end());
	if (temp == input)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}