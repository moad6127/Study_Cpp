#include <bits/stdc++.h>

using namespace std;

string a;
int countA[30];
int main()
{
	cin >> a;
	for (auto e : a)
	{
		countA[e - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << countA[i] << " ";
	}
}