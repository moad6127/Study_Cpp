#include <bits/stdc++.h>

using namespace std;

int N;
int a[500004];
int result;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		int maxSize{0};
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] < a[j])
			{
				result++;
				break;
			}
			else
			{
				if (maxSize <= a[j])
				{
					maxSize = a[j];
					result++;
				}
			}
		}
	}
	cout << result;
}