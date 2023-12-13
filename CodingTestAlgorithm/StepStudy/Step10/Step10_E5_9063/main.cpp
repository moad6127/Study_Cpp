#include <bits/stdc++.h>

using namespace std;

int N;
int minY = 987654321, maxY = -9876543, minX = 987654321, maxX= -9876543;
int A, B;
long long result;
int main()
{
	cin >> N;
	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		minX = min(minX, A);
		maxX = max(maxX, A);
		minY = min(minY, B);
		maxY = max(maxY, B);
	}
	result = (maxX - minX) * (maxY - minY);
	cout << result;
}