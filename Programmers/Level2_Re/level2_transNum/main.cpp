#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int table[1000004];
int solution(int x, int y, int n) {
    int answer = 0;
    for (int i = x + n; i <= y; i += n)
    {
        table[i] = min(table[i],table[i - n] + 1);
    }
    for (int i = x * 2; i <= y; i *= 2)
    {
        table[i] = min(table[i],table[i/2] + 1);
    } 
    for (int i = x * 3; i <= y; i *= 3)
    {
        table[i] = min(table[i],table[i/3] + 1);
    }
    return table[y] == 0 ? -1 : table[y];
}
int main()
{
    solution(10, 40, 30);
}