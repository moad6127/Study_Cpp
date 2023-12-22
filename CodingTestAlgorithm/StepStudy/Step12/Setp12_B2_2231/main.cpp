#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int sum{};
		sum += i;
		string temp{ to_string(i)};
		for (int j = 0; j < temp.size(); j++)
		{
			sum += temp[j] - '0';
		}
		if (sum == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
}