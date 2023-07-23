#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num{};
	cin >> num;
	string check;
	cin >> check;

	string frontS;
	string backS;
	frontS = check.substr(0, check.find('*'));
	backS = check.substr(check.find("*") + 1);
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;

		if (frontS.size() + backS.size() > s.size())
		{
			cout << "NE" << endl;
		}
		else
		{
			if (frontS == s.substr(0, frontS.size()) && backS == s.substr(s.size() - backS.size()))
			{
				cout << "DA" << endl;
			}
			else
			{
				cout << "NE" << endl;
			}
		}
	}
}