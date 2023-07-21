#include <bits/stdc++.h>

using namespace std;
int main()
{
	string dopa = "abcde";

	cout << dopa.substr(0, 3) << endl;
	reverse(dopa.begin(), dopa.end());
	cout << dopa << endl;
	cout << dopa + "umzunsik" << endl;
}