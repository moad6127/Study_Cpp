#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    int start{};
    int end = arr.size() - 1;
    for (int i = 0; i < query.size(); i++)
    {
        if (i % 2)
        {
            start += query[i];
        }
        else
        {
            end = start + query[i];
        }
    }
    for (int i = start; i <= end; i++)
    {
        answer.push_back(arr[i]);
    }
    return answer;
}