#include <bits/stdc++.h>

using namespace std;

const vector<string> CList{"c=","c-","dz=","d-","lj","nj","s=","z="};

string s;
vector<string> resultList;

int main()
{
	cin >> s;
	while (s.size())
	{
		int resultSize = resultList.size();
		for (auto e : CList)
		{
			if (s.find(e) == 0)
			{
				s = s.substr(e.size());
				resultList.push_back(e);
				break;
			}
		}
		if (resultSize == resultList.size())
		{
			if (s.size())
			{
				string temp;
				temp += s.front();
				resultList.push_back(temp);
				s = s.substr(1);
			}
		}
	}
	cout << resultList.size();
}