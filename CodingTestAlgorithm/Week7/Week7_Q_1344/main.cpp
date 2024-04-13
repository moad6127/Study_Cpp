#include <bits/stdc++.h>

using namespace std;

const vector<int> PRIM{2, 3, 5, 7,11, 13, 17};
const vector<int> NOTPRIM{0,1,4,6,8,9,10,12,14,15,16,18};

double A, B,result;
double a[20];
double b[20];

int main()
{
	cin >> A >> B;
	a[0] = 1;
	b[0] = 1;
	A /= 100;
	B /= 100;

	for (int i = 1; i <= 18; i++)
	{
		a[i] = a[i - 1] * A;
		a[i - 1] -= a[i];
		b[i] = b[i - 1] * B;
		b[i - 1] -= b[i];
	}
	for (int i = 0; i < NOTPRIM.size(); i++)
	{
		for (int j = 0; j < NOTPRIM.size(); j++)
		{
			result += (a[NOTPRIM[i]] * b[NOTPRIM[j]]);
		}
	}
	cout << 1 - result;
}