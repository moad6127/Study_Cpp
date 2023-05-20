#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = static_cast<int>(nums.size());
    unordered_map<int, int> list;
    for (auto e : nums)
    {
        list[e]++;
    }
    if (list.size() > (size / 2) )
    {
        answer = size / 2;
    }
    else
    {
        answer = static_cast<int>(list.size());
    }
    return answer;
}

int main()
{
    vector<int> nums{ 3,1,2,3 };
    solution(nums);
}