#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string toN(int x, int n)
{
    string res;
    if (x == 0)
    {
        return "0";
    }
    while (x)
    {
        int temp = x % n;
        res += to_string(temp);
        x /= n;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool checkPrim(long long n)
{
    if (n < 2)
    {
        return false;
    }
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}


int solution(int n, int k) {
    int answer = 0;
    string bitNum = toN(n, k);

    while (bitNum.size())
    {
        if (bitNum.find('0') == string::npos)
        {
            break;
        }
        string temp = "0" + bitNum.substr(0, bitNum.find('0'));
        bitNum = bitNum.substr(bitNum.find('0') + 1);
        if (checkPrim(stoll(temp)))
        {
            answer++;
        }
    }
    if (!bitNum.empty() && checkPrim(stoll(bitNum)))
    {
        answer++;
    }
    return answer;
}

int main()
{
    solution(797161, 3);
}