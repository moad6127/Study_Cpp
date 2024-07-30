#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
    string stA = to_string(a);
    string stB = to_string(b);
    string stAB = stA + stB;
    string stBA = stB + stA;
    return stAB > stBA;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), comp);

    for (auto e : numbers)
    {
        answer += to_string(e);
    }
    if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}

int main()
{
    solution({ 3, 30, 34, 5, 9 });
}