#include <bits/stdc++.h>


using namespace std;
vector<string> result;
int N;

bool comp(string a, string b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	return a < b;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input{};
		cin >> input;
		string numTemp{};
		for (auto e : input)
		{
			if (isdigit(e))
			{
				numTemp += e;
			}
			else
			{
				if (!numTemp.empty())
				{
					while (true)
					{
						if (numTemp == "0")
						{
							break;
						}
						if (numTemp.front() != '0')
						{
							break;
						}
						numTemp = numTemp.substr(1);
					}
					result.push_back(numTemp);
					numTemp.clear();
				}
			}
		}
		if (!numTemp.empty())
		{
			while (true)
			{
				if (numTemp == "0")
				{
					break;
				}
				if (numTemp.front() != '0')
				{
					break;
				}
				numTemp = numTemp.substr(1);
			}
			result.push_back(numTemp);
		}

	}

	sort(result.begin(), result.end(),comp);
	for (auto e : result)
	{
		cout << e << '\n';
	}
}