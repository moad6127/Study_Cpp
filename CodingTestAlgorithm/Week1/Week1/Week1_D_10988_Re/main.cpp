#include <bits/stdc++.h>


using namespace std;

string a;
int main()
{
	cin >> a;
	string temp{a};
	reverse(temp.begin(), temp.end());
	cout<< (temp == a ? 1 : 0);
}