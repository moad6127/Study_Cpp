#include <bits/stdc++.h>

using namespace std;

int x, result = 1;

int main()
{
	cin >> x;
	while (x != 1)
	{
		if (x & 1)
		{
			result++;
		}
		x /= 2;
	}

	cout << result;
}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int X;
//    cin >> X;
//
//    int stick = 64;
//    int count = 0;
//
//    while (X > 0) {
//        if (stick > X) {
//            stick /= 2;
//        }
//        else {
//            count++;
//            X -= stick;
//        }
//    }
//
//    cout << count << endl;
//    return 0;
//}