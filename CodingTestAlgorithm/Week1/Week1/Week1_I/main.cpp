#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int count{}, num{};
	cin >> count >> num;
	map<int, string> iToS;
	map<string, int> sToI;

	for (int i = 1; i <= count; i++)
	{
		string input;
		cin >> input;
		sToI[input] = i;
		iToS[i] = input;
	}

	for (int i = 0; i < num; i++)
	{
		string s{};
		cin >> s;
		if (sToI.count(s))
		{
			cout << sToI[s] << '\n';
		}
		else
		{
			cout << iToS[stoi(s)] << '\n';
		}
	}
}