#include <bits/stdc++.h>

using namespace std;

long long dp[51];
long long M;
string TEMP{"Messi Gimossi Messi Messi Gimossi Messi Gimossi Messi"};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 5;
	dp[2] = 5 + 7 + 1;
	for (int i = 3; i <= 40; i++)
	{
		dp[i] = dp[i - 1] + 1 + dp[i - 2];
	}
	cin >> M;
	M--;
	for (int i = 40; i >= 2; i--)
	{
		if (dp[i] < M)
		{
			M = M - dp[i] - 1;
		}
	}

	if (TEMP[M] == ' ')
	{
		cout << "Messi Messi Gimossi"<<'\n';
	}
	else
	{
		cout << TEMP[M]<<'\n';
	}
	

}