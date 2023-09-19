
#include <bits/stdc++.h>

using namespace std;

//
// 
// 비트 연산자
// 
//  &, |, ^, ~ ,>> ,<< 등의 연산자가 있다.
// 
// 비트연산 + , -
// 
// 10진수와 비슷하게 더하고 빼면 된다.
// 
// 
// 
// & , |연산자
// 
// & 연산자는 and연산을 한다
// | 연산자는 or연산을 한다
// 
// & 연산
// 
// & 일때 true & true 이면 true이고 나머지는 모두 false를 반환한다
// 
// 즉 
// 0 & 0 = 0
// 1 & 0 = 0
// 0 & 1 = 0
// 1 & 1 = 1
// 이러한 값이 된다.
// 
// 1001 & 1000 = 이 된다.
// 
// ex)
//int main()
//{
//	int a{ 8 };
//	int b{ 9 };
//	cout << (a & b) << '\n'; // == 8이 나온다.
// 
//}
//
// | 연산
// 0 | 0 = 0
// 1 | 0 = 1
// 0 | 1 = 1
// 1 | 1 = 1
//
// 하나라도 true이면 true가 된다.
// 
// 1001 | 1000 = 1001 이 된다.
// 
// 1001 | 0110 = 1111 이된다.
// 
// 
// ex)
//
//int main()
//{
//	int a{ 7 };
//	int b{ 9 };
//	cout << (a | b) << '\n';
//}
// 
// Shift연산자 <<, >>
// 
// << 연산
// 왼쪽으로 이동시키는 연산
// 111<<1 -> 1110 이되고
// 111<<2 -> 11100 이되는 왼쪽으로 이동시키는 연산자이다.
// 
// a<<b -> 는 a * 2^b의 연산을 하는것과 같다
// 
// ex
//int main()
//{
//	int a = 7;
//	cout << (a << 3) << '\n'; //56이 나온다.
//
//}
//
// 비트마스킹에서는 주로
// 1<<b를 사용해서 값을 구한다.
// 
// 1<<4 -> 10000
// 이러한 연산을 이용해 비트마스킹으로 사용한다.
// 몇번째 비트가 켜져있는지 확인하기위해 사용한다.
// 
// >>연산
// 오른쪽으로 이동시키는 연산
// 101 >> 1 -> 10
// 
//int main()
//{
//	cout << (11 >> 2) << '\n'; // 2가 나온다
//}
// 
// a >> b -> a * (1/2)^b이러한 연산을 한다
// 
// 
// ^와 ~연산
// 
// ^ 연산
// 
// ^는 XOR연산을 하며 같은수를 연산하면 false를 반환하고 다른수를 연산하면 true를 반환한다.
// 
// 0 ^ 0 -> 0
// 0 ^ 1 -> 1
// 1 ^ 0 -> 1
// 1 ^ 1 -> 0
// 
// 1001 ^ 1000연산을 하게되면
// 0001 이 된다.
//
// 1001 ^ 1010 연산은
// 0011이 된다.
//
//int main()
//{
//	cout << (9 ^ 10) << '\n';
//}
// 
// ~연산
// 
// ~연산은 비트를 반전시키는 연산을 한다.
// 
// ~ Value = -(Value + 1) 의 값을 가지게 된다.
// 
// ~0011 -> 1100의 값을 가지게 된다.
// 
//int main()
//{
//	int a{ 3 };
//	cout << (~a) << '\n'; // -4가 나오게 된다.
//
//}
//