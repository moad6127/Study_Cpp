#include <bits/stdc++.h>

using namespace std;

string s,temp;
int main()
{
	cin >> s;
	temp = s;
	reverse(s.begin(), s.end());
	s == temp ? cout<<1 : cout<<0;
}