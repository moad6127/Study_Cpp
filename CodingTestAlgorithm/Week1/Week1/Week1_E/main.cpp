#include <bits/stdc++.h>


using namespace std;

int main()
{
	int num{};
	cin >> num;
	int list[26]{};
	string out{};
	for (int i = 0; i < num; i++)
	{
		string input{};
		cin >> input;
		list[input.front() - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (list[i] >= 5)
		{
			out += ('a' + i);
		}
	}
	if (out.empty())
	{
		cout << "PREDAJA";
	}
	else
	{
		cout << out;
	}
}