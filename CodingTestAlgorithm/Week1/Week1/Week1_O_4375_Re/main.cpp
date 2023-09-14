#include <bits/stdc++.h>


using namespace std;
int N;
int main()
{

	while (cin >> N)
	{
		int result{ 1 };
		long long check{ 1 };
		while (true)
		{
			if (check % N == 0)
			{
				check = 1;
				break;
			}
			check = (check * 10 + 1);
			check %= N;
			result++;
		}
		cout << result<<'\n';
	}
}