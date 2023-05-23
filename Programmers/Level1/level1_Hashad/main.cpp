#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string temp = to_string(x);
    int sum{};
    for (auto e : temp)
    {
        sum += e - '0';
    }

    return x % sum ? false : true;
}
int main()
{
    solution(10);
}