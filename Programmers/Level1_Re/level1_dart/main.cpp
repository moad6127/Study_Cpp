#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> darts;
    string temp;
    vector<int> nums;
    for (auto e : dartResult)
    {
        temp += e;
        if (e == 'S' || e == 'D' || e == 'T')
        {
            darts.push_back(temp);
            temp.clear();
        }
        if (e == '*' || e == '#')
        {
            darts.back().push_back(e);
            temp.clear();
        }
    }
    for (auto e : darts)
    {
        bool as{ false };
        bool ac{ false };
        char m{};
        int temp{};
        if (e.back() == '*')
        {
            as = true;
            e.pop_back();
        }
        if (e.back() == '#')
        {
            ac = true;
            e.pop_back();
        }
        m = e.back();
        e.pop_back();
        temp = stoi(e);
        if (m == 'D')
        {
            temp = temp * temp;
        }
        if (m == 'T')
        {
            temp = temp * temp * temp;
        }
        if (ac)
        {
            temp *= -1;
        }
        if (as)
        {
            temp *= 2;
            if (!nums.empty())
            {
                nums.back() *= 2;
            }
        }
        nums.push_back(temp);
    }
    for (auto e : nums)
    {
        answer += e;
    }

    return answer;
}

int main()
{
    solution("1S*2T*3S");
}