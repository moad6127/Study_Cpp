#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [&](string& a, string& b)
        {
            if (a[n] == b[n])
            {
                return a < b;
            }
            return a[n] < b[n];
        });
    return strings;

}
int main()
{

}