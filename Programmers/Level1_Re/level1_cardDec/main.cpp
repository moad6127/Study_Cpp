#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int card1Idx{};
    int card2Idx{};
    for (int i = 0; i < goal.size(); i++)
    {
        if (goal[i] == cards1[card1Idx])
        {
            card1Idx++;
            continue;
        }
        else if (goal[i] == cards2[card2Idx])
        {
            card2Idx++;
            continue;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    return answer;
}