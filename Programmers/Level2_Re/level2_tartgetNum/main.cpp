#include <string>
#include <vector>

using namespace std;

int Func(vector<int>& numbers, int target,int here, int sum)
{
    if (here >= numbers.size())
    {
        if (sum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return  Func(numbers, target, here + 1, sum + numbers[here]) + Func(numbers, target, here + 1, sum - numbers[here]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = Func(numbers, target, 0, 0);
    return answer;
}

int main()
{
    solution({ 1,1,1,1,1 }, 3);
}