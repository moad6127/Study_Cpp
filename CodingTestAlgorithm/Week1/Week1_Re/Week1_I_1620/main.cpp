#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;

unordered_map<int, string> nToS;
unordered_map<string, int> sToN;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		nToS[i] = s;
		sToN[s] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9')
		{
			cout << nToS[stoi(s)] << '\n';
		}
		else
		{
			cout << sToN[s] << '\n';
		}
	}
}