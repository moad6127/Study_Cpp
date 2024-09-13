#include <bits/stdc++.h>

using namespace std;

int n;
string pa;
string s;
int main()
{
	cin >> n>>pa;
	string front;
	string back;
	front = pa.substr(0, pa.find('*'));
	back = pa.substr(pa.find('*') + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s.size() < front.size() + back.size())
		{
			cout << "NE" << '\n';
			continue;
		}
		else
		{
			if (front == s.substr(0, front.size()) && back == s.substr(s.size() - back.size()))
			{
				cout<<"DA"<<'\n';
			}
			else
			{
				cout << "NE" << '\n';
			}
		}
	}
}