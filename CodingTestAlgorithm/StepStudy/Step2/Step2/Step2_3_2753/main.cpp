#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	cin >> N;
	((N % 4 == 0 && N % 100 != 0) || N % 400 == 0) ? cout << 1 : cout << 0;

}