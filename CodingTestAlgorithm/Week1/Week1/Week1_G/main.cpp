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
	backS = check.substr(check.find("*") + 1, check.back());
	reverse(backS.begin(), backS.end());
	for (int i = 0; i < num; i++)
	{
		string s , temp;
		cin >> s;
		temp = s;
		reverse(s.begin(), s.end());
		if (temp.find(frontS) == 0 && s.find(backS) == 0)
		{
			cout << "DA" << endl;
		}
		else
		{
			cout << "NE" << endl;
		}
	}
}