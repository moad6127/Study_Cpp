#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    pair<int, int> maxSize{};
    for (int i = 0; i < sizes.size(); i++)
    {
        maxSize.first = max(min(sizes[i][0],sizes[i][1]), maxSize.first);
        maxSize.second = max(max(sizes[i][1],sizes[i][0]), maxSize.second);
    }
    answer = maxSize.first * maxSize.second;
    return answer;
}