#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int start = section[0];
    int end = start + m - 1;
    for (int i = 0; i < section.size(); i++)
    {
        if (section[i] <= end)
        {
            continue;
        }
        start = section[i];
        end = start + m - 1;
        answer++;
    }
    return answer;
}