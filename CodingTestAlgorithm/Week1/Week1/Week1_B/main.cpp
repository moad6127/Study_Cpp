#include <bits/stdc++.h>

using namespace std;

//map���� Ǯ��


/*
int main()
{
	map<char, int> list;
	char a{ 'a' };
	for (int i = 0; i < 26; i++)
	{
		list[a] = 0;
		a++;
	}
	string input{};
	cin >> input;

	for (auto e : input)
	{
		list[e]++;
	}

	for (auto e : list)
	{
		cout << e.second << " ";
	}
	return 0;
}*/

int main()
{
	int Array[26]{};
	string input{};
	cin >> input;
	for (auto e : input)
	{
		Array[e - 'a']++;
	}
	for (auto e : Array)
	{
		cout << e << " ";
	}
}
