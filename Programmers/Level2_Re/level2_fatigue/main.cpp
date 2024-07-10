#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int visit[10];
int Func(vector<vector<int>>& dungeons, int k)
{
    int result{};
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visit[i])
        {
            continue;
        }
        if (k >= dungeons[i][0])
        {
            visit[i] = 1;
            result = max(result, Func(dungeons, k - dungeons[i][1]) + 1);
            visit[i] = 0;
        }
    }
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer{};

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (k >= dungeons[i][0])
        {
            visit[i] = 1;
            answer = max(answer, Func(dungeons, k - dungeons[i][1]) + 1);
            visit[i] = 0;
        }
    }
    return answer;
}
int main()
{
    solution(80, { {80,20},{50,40},{30,10} });
}