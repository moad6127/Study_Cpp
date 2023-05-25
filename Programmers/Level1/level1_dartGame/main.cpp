#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> nums(3, 0);
    vector<string> result;
    string temp{dartResult[0]};

    for (int i = 1; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if (temp.size() == 1)
            {
                temp += dartResult[i];
                continue;
            }
            result.push_back(temp);
            temp.clear();
        }
        temp += dartResult[i];
    }
    result.push_back(temp);
    temp.clear();
    for (int i = 0; i < 3; i++)
    {
        int num{};
        int po{};
        char op{};
        if (result[i].back() == '*' || result[i].back() == '#')
        {
            op = result[i].back();
            result[i].pop_back();
        }
        if (result[i].back() == 'S')
        {
            po = 1;
        }
        else if (result[i].back() == 'D')
        {
            po = 2;
        }
        else
        {
            po = 3;
        }
        result[i].pop_back();
        num = stoi(result[i]);
        nums[i] = pow(num, po);
        if (op == '*')
        {
            if (i > 0)
            {
                nums[i - 1] *= 2;
            }
            nums[i] *= 2;
        }
        else if (op == '#')
        {
            nums[i] *= -1;
        }
    }
    for (auto e : nums)
    {
        answer += e;
    }
    return answer;

}
int main()
{
    solution("1D2S#10S");
}