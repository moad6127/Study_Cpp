#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string temp;
    int sum{};
    temp = to_string(x);
    for (auto e : temp)
    {
        sum += e - '0';
    }
    answer = !(x % sum);
    return answer;
}