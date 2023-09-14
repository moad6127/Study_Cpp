#include <bits/stdc++.h>


using namespace std;
string s;
int ACount[26];
int bCount;
char centerA;
string result;
int main()
{
	cin >> s;
	for (auto e : s)
	{
		ACount[e - 'A']++;
	}
	for (int i = 0 ; i<26;i++)
	{
		if (ACount[i] % 2 == 1)
		{
			bCount++;
			result = i + 'A';
			ACount[i]--;
		}
	}
	if (bCount >= 2)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 26; i >= 0; i--)
	{
		if (ACount[i])
		{
			int AddCount = ACount[i] / 2;
			string temp;
			for (int j = 0; j < AddCount; j++)
			{
				temp += i + 'A';
				result += i + 'A';
			}
			result = temp + result;
		}
	}
	cout << result;
}