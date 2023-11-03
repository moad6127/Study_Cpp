#include<bits/stdc++.h>

using namespace std;

int X,N;
int a, b;

int main()
{
	cin >> X >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		X -= (a * b);
	}
	X ? cout << "No" : cout << "Yes";
}