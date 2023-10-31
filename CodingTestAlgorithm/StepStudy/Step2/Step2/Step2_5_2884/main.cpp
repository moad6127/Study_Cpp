#include <bits/stdc++.h>

using namespace std;

int H, M;
const int MaxM{60 + 23*60};
int main()
{
	cin >> H >> M;
	M += 60 * H;

	M -= 45;
	if (M < 0)
	{
		M += MaxM;
	}
	H = M / 60;
	M = M % 60;

	cout << H << " " << M;
}