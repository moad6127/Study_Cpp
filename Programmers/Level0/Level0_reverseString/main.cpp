#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for (auto e : queries)
    {
        reverse(my_string.begin() + e[0], my_string.begin() + e[1] + 1);
    }
    return my_string;
}
int main()
{
    vector<vector<int>> q {{2, 3}, { 0, 7 }, { 5, 9 }, { 6, 10 }};
    solution("rermgorpsam", q);
}