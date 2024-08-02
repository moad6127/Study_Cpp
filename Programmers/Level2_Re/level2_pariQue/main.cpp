#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer{};
    long long sum1{};
    long long sum2{};
    queue<int> que1;
    queue<int> que2;
    int check = queue1.size();
    for (int i = 0; i < queue1.size(); i++)
    {
        sum1 += queue1[i];
        que1.push(queue1[i]);
        sum2 += queue2[i];
        que2.push(queue2[i]);
    }
    if ((sum1 + sum2) % 2 != 0)
    {
        return -1;
    }
    while (true)
    {
        if (answer > 1000000)
        {
            return -1;
        }
        if (sum1 == sum2)
        {
            break;
        }
        if (sum1 > sum2)
        {
            int move = que1.front();
            que1.pop();
            que2.push(move);
            sum1 -= move;
            sum2 += move;
        }
        else
        {
            int move = que2.front();
            que2.pop();
            que1.push(move);
            sum2 -= move;
            sum1 += move;
        }
        answer++;
    }

    return answer;
}

int main()
{
    solution({ 3,2,7,2 }, { 4,6,5,1 });
}