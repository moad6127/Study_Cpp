#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(),greater<>());

    int left{ 0 };
    int right = people.size() - 1;
    while (true)
    {
        if (left == right)
        {
            answer += 1;
            break;
        }
        if (left > right)
        {
            break;
        }
        answer += 1;
        if (limit >= people[left] + people[right])
        {
            left++;
            right--;
        }
        else
        {
            left++;
        }
    }

    return answer;
}

int main()
{
    solution({ 70,50,80,50 }, 100);
}