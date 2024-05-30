#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const vector<pair<int, int>>NUMSLOC{{3, 1}, { 0,0 }, { 0,1 }, { 0,2 }, { 1,0 }, { 1,1 }, { 1,2 }, { 2,0 }, { 2,1 }, { 2,2 }};

char Center(pair<int, int> left, pair<int, int> right, int cen, string hand)
{
    if (abs(left.first - NUMSLOC[cen].first) + abs(left.second - NUMSLOC[cen].second) == abs(right.first - NUMSLOC[cen].first) + abs(right.second - NUMSLOC[cen].second))
    {
        return toupper(hand[0]);
    }
    else if (abs(left.first - NUMSLOC[cen].first) + abs(left.second - NUMSLOC[cen].second) < abs(right.first - NUMSLOC[cen].first) + abs(right.second - NUMSLOC[cen].second))
    {
        return 'L';
    }
    else 
    {
        return 'R';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left{3, 0};
    pair<int, int> right{3, 2};
    for (auto e : numbers)
    {
        if (e == 1 || e == 4 || e == 7)
        {
            answer.push_back('L');
            left = NUMSLOC[e];
        }
        else if (e == 3 || e == 6 || e == 9)
        {
            answer.push_back('R');
            right = NUMSLOC[e];
        }
        else
        {
            answer.push_back(Center(left, right, e, hand));
            if (answer.back() == 'L')
            {
                left = NUMSLOC[e];
            }
            else
            {
                right = NUMSLOC[e];
            }
        }
    }
    return answer;
}