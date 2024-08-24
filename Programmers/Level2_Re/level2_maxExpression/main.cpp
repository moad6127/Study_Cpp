#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string EXPRE{ "*+-" };

long long Comp(long long a, long long b, char co)
{
    if (co == '*')
    {
        return a * b;
    }
    else if (co == '+')
    {
        return a + b;
    }
    return a - b;
}

long long Func(vector<long long> nums, vector<char> exp)
{
    for (int i = 0; i < EXPRE.size(); i++)
    {
        for (int j = 0; j < exp.size(); j++)
        {
            if (exp[j] == EXPRE[i])
            {
                long long temp = Comp(nums[j], nums[j + 1], exp[j]);
                nums[j] = temp;
                nums.erase(nums.begin() + j + 1);
                exp.erase(exp.begin() + j);
                j--;
            }
        }
    }
    if (exp.empty())
    {
        return nums[0];
    }
    return Comp(nums[0],nums[1],exp[0]);
}
long long solution(string expression) {
    long long answer = -1;
    sort(EXPRE.begin(), EXPRE.end());
    vector<long long> number;
    vector<char> exp;
    string temp;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            temp += expression[i];
        }
        else
        {
            number.push_back(stoi(temp));
            exp.push_back(expression[i]);
            temp.clear();
        }
    }
    number.push_back(stoi(temp));
    do
    {
        answer = max(abs(Func(number, exp)), answer);
    } while (next_permutation(EXPRE.begin(), EXPRE.end()));

    return answer;
}

int main()
{
    solution("177-661*999*99-133+221+334+555-166-144-551-166*166-166*166-133*88*55-11*4+55*888*454*12+11-66+444*99");
}