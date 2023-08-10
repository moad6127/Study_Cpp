#include <bits/stdc++.h>

using namespace std;
const string CHECKSTRING{ "aeiou" };


bool FRule(string input)
{
	for (auto e : input)
	{
		if (CHECKSTRING.find(e) != string::npos)
		{
			return true;
		}
	}
	return false;
}
bool SRule(string input)
{
	int vowelCount{};
	int consonantCount{};
	for (auto e : input)
	{
		if (CHECKSTRING.find(e) != string::npos)
		{
			consonantCount++;
			vowelCount = 0;
		}
		else
		{
			consonantCount = 0;
			vowelCount++;
		}
		if (vowelCount >= 3 || consonantCount >= 3)
		{
			return false;
		}
	}
	return true;
}
bool TRule(string input)
{
	stack<char>a;
	for (auto e : input)
	{
		if (a.empty())
		{
			a.push(e);
		}
		else
		{
			if (a.top() == e)
			{
				if (a.top() == 'e' || a.top() == 'o')
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			else
			{
				a.push(e);
			}
		}
	}
	return true;
}

int main()
{
	string input{};
	while (true)
	{
		cin >> input;
		if (input == "end")
		{
			break;
		}
		bool check{};
		check = FRule(input) && SRule(input) && TRule(input);
		if (check)
		{
			cout << "<" << input << "> " << "is acceptable." << '\n';
		}
		else
		{
			cout << "<" << input << "> " << "is not acceptable." << '\n';
		}
	}
}