#include <bits/stdc++.h>

using namespace std;


string m{ "aeiou" };
string s;
string T{ " is acceptable." };
string F{ " is not acceptable." };

bool FirR(string s)
{
	int a[26];
	memset(a, 0, sizeof(a));
	for (auto e : s)
	{
		a[e - 'a']++;
	}
	for (auto e : m)
	{
		if (a[e - 'a'])
		{
			return true;
		}
	}
	return false;
}
bool SecR(string s)
{
	int mCnt{};
	int Cnt{};
	for (auto e : s)
	{
		if (m.find(e) == string::npos)
		{
			if (mCnt)
			{
				mCnt = 0;
			}
			Cnt++;
		}
		else
		{
			if (Cnt)
			{
				Cnt = 0;
			}
			mCnt++;
		}
		if (mCnt >= 3 || Cnt >= 3)
		{
			return false;
		}
	}
	return true;
}
bool ThR(string s)
{
	stack<char> st;
	for (auto e : s)
	{
		if (st.size() && st.top() == e)
		{
			if (e == 'e' || e == 'o')
			{
				continue;
			}
			return false;
		}
		st.push(e);
	}
	return true;
}

int main()
{
	while (true)
	{
		cin >> s;
		if (s == "end")
		{
			break;
		}
		if (FirR(s) && SecR(s) && ThR(s))
		{
			cout << "<" << s << ">" << T << '\n';
		}
		else
		{
			cout << "<" << s << ">" << F << '\n';
		}
	}
}