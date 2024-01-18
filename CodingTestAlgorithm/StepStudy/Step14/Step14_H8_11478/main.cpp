#include <bits/stdc++.h>

using namespace std;

string s;
set<string> ss;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> s;
	string temp;
	for (int i = 0; i < s.size(); i++)
	{

		for (int j = i; j < s.size(); j++)
		{
			temp.push_back(s[j]);
			ss.insert(temp);
		}
		temp.clear();
	}
	cout << ss.size();
}