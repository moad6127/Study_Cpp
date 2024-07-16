#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> a;
    unordered_map<int, int> b;
    for (int i = 0; i < topping.size(); i++)
    {
        a[topping[i]]++;
    }
    for (int i = 0; i < topping.size(); i++)
    {
        a[topping[i]]--;
        if (a[topping[i]] == 0)
        {
            a.erase(topping[i]);
        }
        b[topping[i]]++;
        if (a.size() == b.size())
        {
            answer++;
        }
    }

    return answer;
}
int main()
{
    solution({ 1, 2, 1, 3, 1, 4, 1, 2 });
}