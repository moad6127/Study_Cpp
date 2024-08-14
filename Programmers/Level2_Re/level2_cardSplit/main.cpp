#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int A{arrayA[0]};
    int B{ arrayB[0] };
    for (int i = 1; i < arrayA.size(); i++)
    {
        A = gcd(A, arrayA[i]);
        B = gcd(B, arrayB[i]);
    }
    for (int i = 0; i < arrayA.size(); i++)
    {
        if (arrayA[i] % B == 0)
        {
            B = 0;
        }
        if (arrayB[i] % A == 0)
        {
            A = 0;
        }
    }

    return max(A,B);
}

int main()
{
    solution({ 10,17 }, { 5,20 });
}