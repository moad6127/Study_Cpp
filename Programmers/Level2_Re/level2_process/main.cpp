#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    int Return{1};
    unordered_map<int, int> mp;
    for (auto e : priorities)
    {
        pq.push(e);
    }
    while (pq.size())
    {
        for (int i = 0; i < priorities.size(); i++)
        {
            if (pq.empty())
            {
                break;
            }
            if (pq.size() && pq.top() == priorities[i])
            {
                mp[i] = Return++;
                pq.pop();
            }
        }
    }
    return mp[location];
}

int main()
{
    solution({ 2, 1, 3, 2 }, 2);
}