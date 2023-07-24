#include <bits/stdc++.h>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input{};
	cin >> input;
	string result{};
	int count[200]{};
	char mid{};
	int check{};
	for (auto e : input)
	{
		count[e]++;
	}
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (count[i])
		{
			if (count[i] & 1)
			{
				mid = char(i);
				check++;
				count[i]--;
			}
			if (check == 2)
			{
				break;
			}
			for (int j = 0; j < count[i]; j += 2)
			{
				result = char(i) + result;
				result += char(i);
			}
		}
	}
	if (mid)
	{
		result.insert(result.begin() + result.size() / 2, mid);
	}
	if (check == 2)
	{
		cout << "I'm Sorry Hansoo";
	}
	else
	{
		cout << result;
	}
}