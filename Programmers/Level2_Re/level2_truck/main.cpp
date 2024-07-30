#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int,int>> bri;
    int now{};
    int briWei{};
    while (true)
    {
        if (now >= truck_weights.size())
        {
            break;
        }
        answer++;
        if (bri.size() && answer - bri.front().second == bridge_length)
        {
            briWei -= bri.front().first;
            bri.pop();
        }
        if (briWei + truck_weights[now] <= weight)
        {
            bri.push({ truck_weights[now],answer });
            briWei += truck_weights[now];
            now++;
        }

    }
    return answer + bridge_length;
}
int main()
{
    solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });
}