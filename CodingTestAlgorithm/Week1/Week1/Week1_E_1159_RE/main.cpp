#include <bits/stdc++.h>


using namespace std;

int N;
int countA[30];
string result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string in;
		cin >> in;
		countA[in.front() - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (countA[i] >= 5)
		{
			result += 'a' + i;
		}
	}
	if (result.size())
	{
		cout << result;
	}
	else
	{
		cout << "PREDAJA";
	}
}