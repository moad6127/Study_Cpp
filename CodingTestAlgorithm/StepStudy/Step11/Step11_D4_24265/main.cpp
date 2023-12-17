#include <bits/stdc++.h>

using namespace std;

int N;
long long result;
int main()
{
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			result++;
		}
	}
	cout << result << '\n' << 2;
}