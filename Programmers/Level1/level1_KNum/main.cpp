#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto e : commands)
    {
        vector<int> tempArray{ array.begin() + e[0] - 1 , array.begin() + e[1] };
        sort(tempArray.begin(), tempArray.end());
        answer.push_back(tempArray[e[2] - 1]);
    }
    return answer;
}

int main()
{
    vector<int> array{ 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands{ {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    solution(array, commands);
}