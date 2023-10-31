#include <bits/stdc++.h>

using namespace std;

int N, H, M;
int main()
{
	cin >> H >> M >> N;

	M += H * 60;
	M += N;

	H = M / 60;
	if (H > 23)
	{
		H -= 24;
	}
	M = M % 60;

	cout << H << " " << M;
}