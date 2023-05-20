#include <string>
#include <vector>

using namespace std;

const vector<string> LIST{ {"FRI"},{"SAT"},{"SUN"},{"MON"},{"TUE"},{"WED"},{"THU"} };
const vector<int> MONTHCOUNT{ 0,31, 29,31,30,31,30,31,31,30,31,30,31 };

string solution(int a, int b) {
    string answer = "";

    int findDay{};
    for (int i = 1; i < a; i++)
    {
        findDay += MONTHCOUNT[i];
    }
    findDay += (b - 1);
    answer = LIST[(findDay % 7)];
    return answer;
}
int main()
{
    solution(5, 26);
}