#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer;

void Func(vector<int> picks, vector<string> minerals, int usePick,int now, int nums)
{
    if (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)
    {
        answer = min(answer, nums);
        return;
    }
    if (picks[usePick] <= 0)
    {
        return;
    }
    if (now >= minerals.size())
    {
        answer = min(answer, nums);
        return;
    }
    picks[usePick]--;
    int useNum{};
    int tempNow = now;
    for (int i = tempNow; i < tempNow + 5; i++)
    {
        if (i >= minerals.size())
        {
            break;
        }
        if (usePick == 0)
        {
            useNum += 5;
            now += 5;
            break;
        }
        else if (usePick == 1)
        {
            if (minerals[i] == "diamond")
            {
                useNum += 5;
            }
            else
            {
                useNum += 1;
            }
        }
        else
        {
            if (minerals[i] == "diamond")
            {
                useNum += 25;
            }
            else if (minerals[i] == "iron")
            {
                useNum += 5;
            }
            else
            {
                useNum++;
            }
        }
        now++;
    }
    Func(picks, minerals, 0, now, nums + useNum); 
    Func(picks, minerals, 1, now, nums + useNum);
    Func(picks, minerals, 2, now, nums + useNum);
}


int solution(vector<int> picks, vector<string> minerals) {
    answer = 987654321;

    Func(picks, minerals, 0, 0, 0);
    Func(picks, minerals, 1, 0, 0);
    Func(picks, minerals, 2, 0, 0);

    return answer;
}

int main()
{
    vector<int> picks{1, 1, 0};
    vector<string> minerals{"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};
    solution(picks, minerals);
}