#include <bits/stdc++.h>


using namespace std;
int N;
int input[1000005];
int output[1000005];
int main()
{
	memset(output, -1, sizeof(output));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		while (s.size())
		{
			if (input[s.top()] >= input[i])
			{
				break;
			}
			output[s.top()] = input[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << output[i] << " ";
	}
}


/*
* 
* 9 5 4 5 2 8
* 
* -1 8 5 8 8 -1
*/