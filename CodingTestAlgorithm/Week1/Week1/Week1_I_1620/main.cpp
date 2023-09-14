#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> sToI;
map<int, string> iToS;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin >> temp;
		sToI[temp] = i;
		iToS[i] = temp;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (sToI.count(temp) == 0)
		{
			cout << iToS[stoi(temp)]<<'\n';
		}
		else
		{
			cout << sToI[temp]<<'\n';
		}
	}
}