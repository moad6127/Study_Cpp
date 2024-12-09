#include <bits/stdc++.h>	

using namespace std;

int t, n;
string s, nums;

deque<int> GetNum(string s)
{
	if (s.size() <= 2)
	{
		return deque<int>();
	}
	deque<int> ans;
	string nums;
	for (int i = 1; i < s.size() - 1;i++)
	{
		if (s[i] == ',')
		{
			ans.push_back(stoi(nums));
			nums.clear();
		}
		else
		{
			nums += s[i];
		}
	}
	ans.push_back(stoi(nums));
	return ans;
}
int main()
{
	cin >> t;
	for (int T = 0; T < t;T++)
	{
		cin >> s >> n >> nums;
		bool flag{ true };
		bool ErrorFlag{ false };
		deque<int> numbers = GetNum(nums);

		for (int i = 0; i < s.size();i++)
		{
			if (s[i] == 'R')
			{
				flag = !flag;
			}
			else
			{
				if (numbers.size())
				{
					if (flag)
					{
						numbers.pop_front();
					}
					else
					{
						numbers.pop_back();
					}
				}
				else
				{
					cout << "error" << '\n';
					ErrorFlag = true;
					break;
				}
			}
		}
		if (ErrorFlag)
		{
			continue;
		}
		else
		{
			cout << "[";
			if (!flag)
			{
				reverse(numbers.begin(), numbers.end());
			}
			for (int i = 0;i < numbers.size();i++)
			{
				cout << numbers[i];
				if (i < numbers.size() - 1)
				{
					cout << ',';
				}
			}
			cout << "]" << '\n';
		}
	}
}