#include <bits/stdc++.h>

using namespace std;

int N;
int a[10004];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		a[temp]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (a[i])
		{
			for (int j = 0; j < a[i]; j++)
			{
				cout << i << '\n';
			}
		}
	}
}