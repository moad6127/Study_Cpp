#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for (auto e : arr)
    {
        if (!(e % divisor))
        {
            answer.push_back(e);
        }
    }
    return answer.empty() ? vector<int>{-1} : answer;
}