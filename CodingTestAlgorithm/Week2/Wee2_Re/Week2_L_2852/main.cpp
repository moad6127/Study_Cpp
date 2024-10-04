#include <bits/stdc++.h>

using namespace std;	

int n, t;
int Sc1, Sc2, time1, time2;
int prevT;
string s;
int Func1(string s)
{
	int min = stoi(s.substr(0, 2));
	int sec = stoi(s.substr(3));

	return 60 * min + sec;
}
string Func2(int a)
{
	int m = a / 60;
	int sec = a % 60;
	string result;
	if (m < 10)
	{
		result += '0';
	}
	result += to_string(m);
	result.push_back(':');
	if (sec < 10)
	{
		result += '0';
	}
	result += to_string(sec);

	return result;
}
int main()
{
	cin >> n;
	int maxTime = Func1("48:00");
	for (int i = 0; i < n; i++)
	{
		cin >> t >> s;
		if (Sc1 > Sc2)
		{
			time1 += Func1(s) - prevT;
		}
		else if (Sc1 < Sc2)
		{
			time2 += Func1(s) - prevT;
		}
		t == 1 ? Sc1++ : Sc2++;
		prevT = Func1(s);
	}
	if (Sc1 > Sc2)
	{
		time1 += maxTime - prevT;
	}
	else if (Sc1 < Sc2)

	{
		time2 += maxTime - prevT;
	}
	cout << Func2(time1) << '\n';
	cout << Func2(time2) << '\n';
}