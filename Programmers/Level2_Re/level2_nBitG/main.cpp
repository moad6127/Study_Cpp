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

vector<char> nbits(int n)
{
    vector<char> result;
    for (int i = 0; i < 3000; i++)
    {
        string in = toN(i, n);
        for (auto e : in)
        {
            result.push_back(e);
        }
    }

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> list = nbits(n);
    int i = p - 1;
    while (true)
    {
        if (answer.size() == t)
        {
            break;
        }
        answer.push_back(list[i]);
        i += m;
    }

    return answer;
}

int main()
{
    solution(3,8,2,1);
}