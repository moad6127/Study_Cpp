#include <bits/stdc++.h>

using namespace std;
int N, M,J;
int result;
int main()
{
	cin >> N >> M >> J;
	int left{1}, right{M};
	for (int i = 0; i < J; i++)
	{
		int a{};
		cin >> a;
		if (left > a)
		{
			while (true)
			{
				if (left == a)
				{
					break;
				}
				result++;
				left--;
				right--;
			}
		}
		else if (right < a)
		{
			while (true)
			{
				if (right == a)
				{
					break;
				}
				result++;
				left++;
				right++;
			}
		}
	}
	cout << result;
}