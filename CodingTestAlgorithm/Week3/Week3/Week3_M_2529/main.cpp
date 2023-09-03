#include <bits/stdc++.h>

using namespace std;
int K;
char a[12];
int visited[10];
string maxNum = "-1";
string minNum = "9999999999";
bool check;
vector<char> NUMBERS = { '0','1','2','3','4','5','6','7','8','9' };

bool CompCheck(char a, char b, char Comp)
{
	if (Comp == '<')
	{
		return a < b;
	}
	else
	{
		return a > b;
	}
}

bool checkFunc(string input)
{
	for (int i = 0; i < K; i++)
	{
		if (!CompCheck(input[i], input[i + 1], a[i]))
		{
			return false;
		}
	}
	return true;
}
void makeMinPermutation(int n, int r, int depth) {
	if (r == depth) {
		string temp;
		for (int i = 0; i <= K; i++)
		{
			temp += NUMBERS[i];
		}
		if (checkFunc(temp))
		{
			minNum = min(minNum, temp);
			check = true;
		}
		return;
	}
	if (check)
	{
		return;
	}
	for (int i = depth; i < n; i++)
	{
		swap(NUMBERS[i], NUMBERS[depth]);
		makeMinPermutation(n, r, depth + 1);
		swap(NUMBERS[i], NUMBERS[depth]);
	}
	return;
}
void makeMaxPermutation(int n, int r, int depth) {
	if (r == depth) {
		string temp;
		for (int i = 0; i <= K; i++)
		{
			temp += NUMBERS[i];
		}
		if (checkFunc(temp))
		{
			maxNum = max(maxNum, temp);
			check = true;
		}
		return;
	}
	if (check)
	{
		return;
	}
	for (int i = depth; i < n; i++)
	{
		swap(NUMBERS[i], NUMBERS[depth]);
		makeMaxPermutation(n, r, depth + 1);
		swap(NUMBERS[i], NUMBERS[depth]);
	}
	return;
}

int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i];
	}
	string temp;
	makeMinPermutation(10, K+1,0);
	sort(NUMBERS.begin(), NUMBERS.end(), greater<>());
	memset(visited, 0, sizeof(visited));
	check = false;
	temp.clear();
	makeMaxPermutation(10, K + 1, 0);

	cout << maxNum << '\n';
	cout << minNum << '\n';
}