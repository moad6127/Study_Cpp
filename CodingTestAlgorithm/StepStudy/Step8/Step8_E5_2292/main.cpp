#include <bits/stdc++.h>

using namespace std;

int N;
int result{ 1 };
int main()
{
	cin >> N;
	while (N > 1)
	{
		N = N - (6 * result++);
	}

	cout << result;


}
