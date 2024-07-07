#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    list<string> lt;
    for (int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        auto it = find(lt.begin(), lt.end(), cities[i]);
        if (it == lt.end())
        {
            answer += 5;
        }
        else
        {
            answer += 1;
            lt.erase(it);
        }
        lt.push_front(cities[i]);
        if (lt.size() > cacheSize)
        {
            lt.pop_back();
        }
    }

    return answer;
}
int main()
{
    solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
}