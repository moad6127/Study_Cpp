#include <bits/stdc++.h>

using namespace std;
int N;
string checkS;
string in;
string out;
int main()
{
	cin >>N>> checkS;
	in = checkS.substr(0, checkS.find('*'));
	out = checkS.substr(checkS.find('*') + 1);
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		if (in == temp.substr(0,in.size()) && out == temp.substr(temp.size() - out.size()))
		{
			cout << "DA" << '\n';
		}
		else
		{
			cout << "NE" << '\n';
		}
	}
}