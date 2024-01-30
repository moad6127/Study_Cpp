#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {

    vector<int> answer;

    for (auto e : arr)
    {
        if (find(answer.begin(), answer.end(), e) == answer.end())
        {
            answer.push_back(e);
        }
    }
    answer.resize(k, -1);

    return answer;
}
int main()
{
    solution({ 0,1,1,0 }, 4);
}