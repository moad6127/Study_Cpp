#include <string>
#include <vector>

using namespace std;

const vector<string> DAY{"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
const vector<int> MON{0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string solution(int a, int b) {
    string answer = "";
    int temp{};
    for (int i = 0; i < a; i++)
    {
        temp += MON[i];
    }
    temp += b - 1;
    answer = DAY[temp % 7];
    return answer;
}
int main()
{
    solution(5, 24);
}