#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cnt{};
    for (auto e : s)
    {
        if (e == 'p' || e == 'P')
        {
            cnt++;
        }
        if (e == 'y' || e == 'Y')
        {
            cnt--;
        }
    }


    return !cnt ? true : false;
}