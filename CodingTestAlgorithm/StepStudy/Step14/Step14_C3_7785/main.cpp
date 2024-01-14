#include <bits/stdc++.h>

using namespace std;

int N;
string name, inout;
map<string, int,greater<string>> Check;
vector<string> v;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name>>inout;
		if (inout == "enter")
		{
			Check[name]++;
		}
		else
		{
			Check[name]--;
		}
	}
	for (auto e : Check)
	{
		if (e.second)
		{
			cout << e.first << '\n';
		}
	}

}