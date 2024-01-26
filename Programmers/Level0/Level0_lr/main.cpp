#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> str_list) {
    auto rFind = find(str_list.begin(), str_list.end(), "r");
    auto lFind = find(str_list.begin(), str_list.end(), "l");
    if (rFind > lFind)
    {
        vector<string> temp(str_list.begin(), lFind);
        return temp;
    }
    else if(rFind < lFind)
    {
        vector<string> temp(rFind + 1, str_list.end());
        return temp;
    }
    return vector<string>{};
}
int main()
{
    vector<string> v{"u","d"};
    vector<string> temp = solution(v);


    return 0;
}