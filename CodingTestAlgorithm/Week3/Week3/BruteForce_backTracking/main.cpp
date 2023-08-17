#include<bits/stdc++.h>
using namespace std;
//
//
//완전탐색
// 
// 브루트포스, exhaustive key search 등의 노가다를 말하며 모든 경우의 수를 체크해보는것을 말한다
// 
// 순열 또는 조합 + 로직 을 사용해서 모든경우의 수를 체크한다
// 
// 보통 최대 경우의 수가 1억 미만일경우 사용이 가능해진다.
// 
// ex) 반복문을 사용하는 완전탐색
//#include<bits/stdc++.h>
//using namespace std;  
//int main() {
//	vector<int> v = {1, 3, 2, 5, 6, 7, 8};
//	for(int i = 0; i < v.size(); i++){
//		if(v[i] == 5){
//			cout << i << "\n";
//			break;
//		}
//	} 
//	int i = 0;
//	while(i < v.size()){
//		if(v[i] == 5){
//			cout << i << "\n";
//			break;
//		}
//		i++;
//	}
//	return 0; 
//}
//[출처] [알고리즘 강의] 3주차. 완전탐색, 백트래킹|작성자 큰돌
// 
// 
// 
// 
//
//ex) 반복문을 활용한 완전 탐색
//int n;
//int main()
//{
//	cin >> n;
//	for (int i = 2400; ; i++)
//	{
//		string input = to_string(i);
//		if (input.find("2400") != string::npos)
//		{
//			n--;
//		}
//		if (n == 0)
//		{
//			cout << i;
//			break;
//		}
//	}
//
//}
//
// 재귀함수를 활용한 완전탐색
// 
// 반복문으로 완전탐색이 가능하면 반복문을 사용하는것이 더 빠르고 좋지만 불가능할경우 재귀함수를 사용한다
// 
// 조합 또는 순열 + DFS,BFS알고리즘이 나오거나
// 경우의 수마다 생각해야되는 로직이 나오면 재귀함수를 할용하는것이 좋다.
// 
// 
//

int n;
vector<int> v;

bool check(int n)
{
	if (n <= 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int go(int idx, int sum)
{
	if (idx == n)
	{
		return check(sum);
	}
	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cout << go(0,0) << '\n';
}