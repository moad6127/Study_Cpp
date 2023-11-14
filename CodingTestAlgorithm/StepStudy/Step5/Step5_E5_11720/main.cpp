#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int result;
int main()
{
	cin >> N >> s;

	for (int i = 0; i < N; i++)
	{
		result += s[i] - '0';
	}
	cout << result;
}