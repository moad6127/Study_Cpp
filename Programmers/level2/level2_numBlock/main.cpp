#include <string>
#include <vector>

using namespace std;

int Func(int num)
{
    if (num == 1)
    {
        return 0;
    }
    vector<long long> check;
    for (long long i = 2; i * i <= num; i++)
    {
        if (num == i)
        {
            return 1;
        }
        if (num % i == 0)
        {
            check.push_back(i);
            if (num / i <= 10000000)
            {
                return num / i;
            }
        }

    }
    if (!check.empty())
    {
        return check.back();
    }

    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (begin; begin <= end; begin++)
    {
        answer.push_back(Func(begin));
    }
    return answer;
}



int main()
{

    solution(100000014, 100000016);
}