#include <bits/stdc++.h>

using namespace std;
string a, b;
int main()
{
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	stoi(a) > stoi(b) ? cout << a : cout << b;
}