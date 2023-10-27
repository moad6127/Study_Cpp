//#include <bits/stdc++.h>
//
//using namespace std;
//string A, B;
//string result;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> A >> B;
//
//	for (auto e : A)
//	{
//		result += e;
//		if (result.size() >= B.size() && result.substr(result.size() - B.size(), B.size()) == B)
//		{
//			result.erase(result.end() - B.size(), result.end());
//		}
//	}
//
//	if (result.size())
//	{
//		cout << result<<'\n';
//	}
//	else
//	{
//		cout << "FRULA" << '\n';
//	}
//}

#include<bits/stdc++.h>

using namespace std;

string A, B;
stack<char> st;
string result;
int main()
{
	cin >> A >> B;
	for (auto e : A)
	{
		st.push(e);
		if (st.size() >= B.size() && st.top() == B.back())
		{
			string temp;
			for (int i = 0; i < B.size(); i++)
			{
				temp += st.top();
				st.pop();
			}
			reverse(temp.begin(), temp.end());
			if (temp != B)
			{
				for (auto k : temp)
				{
					st.push(k);
				}
			}
		}
	}
	int check = st.size();
	for (int i = 0; i < check; i++)
	{
		result += st.top();
		st.pop();
	}
	reverse(result.begin(), result.end());
	if (result.size())
	{
		cout << result;
	}
	else
	{
		cout << "FRULA";
	}
}