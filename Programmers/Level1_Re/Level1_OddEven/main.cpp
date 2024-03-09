#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int num) {
    const vector<string> CHECK{"Even", "Odd"};
    return CHECK[abs(num%2)];
}
int main()
{
    solution(2001);
}