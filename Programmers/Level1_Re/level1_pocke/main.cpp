#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    answer = min(size, (int)nums.size());
    return answer;
}
int main()
{
    solution({ 3, 1, 2, 3 });
}