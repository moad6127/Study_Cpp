#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool comp(vector<int>& a, vector<int>& b)
{
    return a[0] + a[1] > b[0] + b[1];
}


int solution(vector<vector<int>> scores) {
    int answer = 1;
    int sum = scores[0][0] + scores[0][1];
    sort(scores.begin() + 1, scores.end(),comp);

    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
        {
            return  -1;
        }
        int check = scores[i][0] + scores[i][1];
        if (sum < check)
        {
            answer++;
        }
        else
        {
            break;
        }
    }
    int check = answer;
    for (int i = 0; i < check; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
            {
                answer--;
                break;
            }
        }
    }


    return answer;
}

int main()
{
    vector<vector<int>> sc{{2, 9}, { 2,9 }, { 10, 1 }, { 1,10 }, { 11, 0 }, { 0, 11 }, { 6, 5 }, { 6,6 }, { 7,7 }};
    solution(sc);
}