#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (left; left <= right; left++)
    {
        int temp{};
        if (left / n >= left % n)
        {
            temp = (left / n) + 1;
        }
        else
        {
            temp = (left % n) + 1;
        }
        answer.push_back(temp);
    }
    return answer;
}