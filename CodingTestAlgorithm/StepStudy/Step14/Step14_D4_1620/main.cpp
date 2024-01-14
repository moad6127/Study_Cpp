#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> NameList;
map<int, string> NumList;
string name;
string temp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> name;
		NameList[name] = i;
		NumList[i] = name;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		if (atoi(temp.c_str()))
		{
			cout << NumList[stoi(temp)] << '\n';
		}
		else
		{
			cout << NameList[temp] << '\n';
		}
	}
}