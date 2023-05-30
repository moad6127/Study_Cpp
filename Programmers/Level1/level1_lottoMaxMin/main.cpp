#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_map<int, int>list{ {6,1},{5,2},{4,3},{3,4},{2,5},{1,6},{0,6} };
    int zeroCount{};
    int count{};
    for (auto e : lottos)
    {
        if (e == 0)
        {
            zeroCount++;
        }
        else
        {
            if (find(win_nums.begin(), win_nums.end(), e) != win_nums.end())
            {
                count++;
            }
        }
    }

    answer.push_back(list[zeroCount + count]);
    answer.push_back(list[count]);
    return answer;
}
int main()
{
    vector<int> lottos{ 44, 1, 0, 0, 31, 25 };
    vector<int> win_nums{ 31, 10, 45, 1, 6, 19 };
    solution(lottos, win_nums);
}