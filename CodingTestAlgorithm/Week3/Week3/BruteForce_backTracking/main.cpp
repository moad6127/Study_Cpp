#include<bits/stdc++.h>
using namespace std;
//
//
//����Ž��
// 
// ���Ʈ����, exhaustive key search ���� �밡�ٸ� ���ϸ� ��� ����� ���� üũ�غ��°��� ���Ѵ�
// 
// ���� �Ǵ� ���� + ���� �� ����ؼ� ������� ���� üũ�Ѵ�
// 
// ���� �ִ� ����� ���� 1�� �̸��ϰ�� ����� ����������.
// 
// ex) �ݺ����� ����ϴ� ����Ž��
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
//[��ó] [�˰��� ����] 3����. ����Ž��, ��Ʈ��ŷ|�ۼ��� ū��
// 
// 
// 
// 
//
//ex) �ݺ����� Ȱ���� ���� Ž��
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
// ����Լ��� Ȱ���� ����Ž��
// 
// �ݺ������� ����Ž���� �����ϸ� �ݺ����� ����ϴ°��� �� ������ ������ �Ұ����Ұ�� ����Լ��� ����Ѵ�
// 
// ���� �Ǵ� ���� + DFS,BFS�˰����� �����ų�
// ����� ������ �����ؾߵǴ� ������ ������ ����Լ��� �ҿ��ϴ°��� ����.
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