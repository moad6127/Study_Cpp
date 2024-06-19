#include <string>
#include <vector>

using namespace std;
string bitT(int x)
{
    string s;
    while (x)
    {
        if (x & 1)
        {
            s.push_back('1');
        }
        else
        {
            s.push_back('0');
        }
        x /= 2;
    }
    return s;
}
int CheckZ(string s)
{
    int cnt{};
    for (auto e : s)
    {
        if (e == '0')
        {
            cnt++;
        }
    }
    return cnt;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt{};
    int zeroCnt{};
    while (true)
    {
        if (s == "1")
        {
            break;
        }
        int zero = CheckZ(s);
        s = bitT(s.size() - zero);
        cnt++;
        zeroCnt += zero;
    }
    return { cnt, zeroCnt };
}

int main()
{
    solution("110010101001");
}