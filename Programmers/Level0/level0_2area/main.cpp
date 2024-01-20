#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> Check;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 2)
        {
            Check.push_back(i);
        }
    }
    if (Check.size())
    {
        int start = Check.front();
        int end = Check.back();
        for (start; start <= end; start++)
        {
            answer.push_back(arr[start]);
        }
    }
    else
    {
        answer.push_back(-1);
    }
    return answer;
}