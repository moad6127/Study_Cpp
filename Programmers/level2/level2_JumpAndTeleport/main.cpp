#include <iostream>
using namespace std;

int Func(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n % 2)
    {
        return Func(n / 2) + 1;
    }
    else
    {
        return Func(n / 2);
    }
}

int solution(int n)
{
    int ans = 0;

    ans = Func(n);

    return ans;
}
int main()
{
    solution(5000);
}