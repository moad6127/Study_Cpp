#include <bits/stdc++.h>

using namespace std;

string s,b;
double sum, sCount,num, ratingSum;
vector<string> rating{"F", "P", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};

int main()
{
	for (int i = 0; i < 20; i++)
	{
		cin >> s >> num >> b;
		if (b == "P")
		{
			continue;
		}
		sum += num;
		int rat = find(rating.begin(), rating.end(), b) - rating.begin();
		ratingSum += (rat* 0.5) * num;
	}

	cout << ratingSum / sum;

	return 0;
}