#include <bits/stdc++.h>

using namespace std;

int A;
string B;
int main()
{
	cin >> A >> B;


	cout << A * (B.back() - '0')<<'\n';
	cout << A * (B[1] - '0') << '\n';
	cout << A * (B[0] - '0') << '\n';
	cout << A * stoi(B) << '\n';
}