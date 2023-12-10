#include <bits/stdc++.h>


using namespace std;

int X, Y, W, H, result;
int main()
{
	cin >> X >> Y >> W >> H;
	result = min(min(X, W - X),min(Y,H - Y));
	cout << result;
}