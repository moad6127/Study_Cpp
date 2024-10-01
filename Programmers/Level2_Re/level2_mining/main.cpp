#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 987654321;

int Tired(vector<string>& minerals, int pick, int now)
{
    int result{};
    for (int i = now; i < now + 5; i++)
    {
        if (i >= minerals.size())
        {
            break;
        }
        if (pick == 0)
        {
            result += 1;
        }
        if (pick == 1)
        {
            if (minerals[i] == "diamond")
            {
                result += 5;
            }
            else
            {
                result += 1;
            }
        }
        if (pick == 2)
        {
            if (minerals[i] == "diamond")
            {
                result += 25;
            }
            else if(minerals[i] =="iron")
            {
                result += 5;
            }
            else
            {
                result += 1;
            }
        }
    }
    return result;
}

void Func(vector<int> Picks, vector<string>& minerals,int now, int num)
{
    if (now >= minerals.size())
    {
        answer = min(answer, num);
        return;
    }
    if (Picks[0] + Picks[1] + Picks[2] == 0)
    {
        answer = min(answer, num);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (Picks[i])
        {
            Picks[i]--;
            Func(Picks, minerals, now + 5, num + Tired(minerals, i, now));
            Picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    for (int i = 0; i < 3; i++)
    {
        if (picks[i] == 0)
        {
            continue;
        }
        Func(picks, minerals, 0, 0);
    }

    return answer;
}

int main()
{
    solution({1,3,2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" });
}