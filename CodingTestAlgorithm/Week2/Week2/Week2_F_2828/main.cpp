#include <bits/stdc++.h>


using namespace std;

int N, M,countNum;

int main()
{
	cin >> N >> M >> countNum;
	int startBox{ 1 };
	int endBox{ M };
	int result{};
	for (int i = 0; i < countNum; i++)
	{
		int apple{};
		cin >> apple;

		while (true)
		{
			if (startBox <= apple && apple <= endBox)
			{
				break;
			}
			if (apple < startBox)
			{
				startBox--;
				endBox--;
			}
			if (apple > endBox)
			{
				startBox++;
				endBox++;
			}
			result++;
		}
	}
	cout << result;

}