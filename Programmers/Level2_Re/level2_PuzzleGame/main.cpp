#include <string>
#include <vector>

using namespace std;

long long TimeCheck(int mid,vector<int>& diffs, vector<int>& times)
{
    long long result{times[0]};
    for (int i = 1; i < times.size(); i++)
    {
        if (mid < diffs[i])
        {
            int cnt{ diffs[i] - mid };
            int needT{ times[i] + times[i - 1] };
            result += cnt * needT + times[i];
        }
        else
        {
            result += times[i];
        }
    }
    return result;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000;
    int left{ 1 };
    int right{ 100000 };
    while (true)
    {
        if (left > right)
        {
            break;
        }
        int mid = (left + right) / 2;
        long long Time = TimeCheck(mid, diffs, times);
        if (Time == limit)
        {
            answer = min(mid,answer);
            break;
        }
        else if (Time > limit)
        {
            left = mid + 1;
        }
        else
        {
            answer = min(mid, answer);
            right = mid - 1;
        }
    }
    return answer;
}
int main()
{
    solution({ 1, 99999, 100000, 99995 }, { 9999, 9001, 9999, 9001 }, 3456789012);
}