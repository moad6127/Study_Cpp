#include <bits/stdc++.h>


using namespace std;
int T,N;
string FunS, nums;

vector<int> GetNums(string nums)
{
	string check;
	vector<int> result;
	for (auto e : nums)
	{
		if (isdigit(e))
		{
			check += e;
		}
		else
		{
			if (check.size())
			{
				result.push_back(stoi(check));
				check.clear();
			}
		}
	}
	return result;
}

void PrintOut(int start, int end,bool bCheck, vector<int> list)
{
	cout << "[";
	if (bCheck)
	{
		for (int i = start; i < end - 1; i++)
		{
			cout << list[i] << ",";
		}
		cout << list[end - 1] << "]"<<'\n';
	}
	else
	{
		for (int i = end - 1; i > start; i--)
		{
			cout << list[i] << ",";
		}
		cout << list[start] << "]" << '\n';
	}
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> FunS >> N >> nums;
		vector<int> list = GetNums(nums);
		int start{};
		int end{N};
		bool bCheck{ true };

		for (auto e : FunS)
		{
			if (e == 'R')
			{
				bCheck = !bCheck;
			}
			else if (e == 'D')
			{
				if (bCheck)
				{
					start++;
				}
				else
				{
					end--;
				}
			}
		}
		if (start > end)
		{
			cout << "error" << '\n';
		}
		else if (start == end)
		{
			cout << "[]" << '\n';
		}
		else
		{
			PrintOut(start, end, bCheck, list);
		}

	}
}