#include <bits/stdc++.h>

using namespace std;

int V, A, B;
int result;
int main()
{
	cin >> A >> B >> V;

	if ((V - A) % (A - B))
	{
		result = (V - A) / (A - B) + 2;
	}
	else
	{
		result = (V - A) / (A - B) + 1;
	}



	cout << result;
}