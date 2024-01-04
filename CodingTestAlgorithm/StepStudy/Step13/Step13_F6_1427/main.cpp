#include <bits/stdc++.h>

using namespace std;

string a;
int main()
{
	cin >> a;
	sort(a.begin(), a.end(),greater<>());
	cout << a;
}