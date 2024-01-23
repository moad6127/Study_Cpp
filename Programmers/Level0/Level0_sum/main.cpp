#include <bits/stdc++.h>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int aSize = a.size();
    int bSize = b.size();
    int c{};
    while (aSize > 0 || bSize > 0)
    {
        int an{};
        if (aSize > 0)
        {
            an = a[--aSize] - '0';
        }
        int bn{};
        if (bSize>0)
        {
            bn = b[--bSize] - '0';
        }
        int in = an + bn + c;
        c = in / 10;
        in %= 10;
        answer += in + '0';
    }
    if (c)
    {
        answer += c + '0';
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main()
{
    solution("18446744073709551615", "287346502836570928366");
}