#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int start{};
    int end = arr.size() - 1;
    while (true)
    {
        if (arr[start] == 2 && arr[end] == 2)
        {
            break;
        }
        if (start >= end)
        {
            break;
        }
        if (arr[start] != 2)
        {
            start++;
        }
        if (arr[end] != 2)
        {
            end--;
        }
    }
    vector<int> answer(arr.begin() + start, arr.begin()+ end + 1);
    if (answer.front() != 2)
    {
        return vector<int>{-1};
    }
    return answer;
}
int main()
{
    vector<int>arr{1, 1, 1};
    solution(arr);
}