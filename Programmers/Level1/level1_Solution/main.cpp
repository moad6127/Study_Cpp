#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Check(vector<vector<string>>& park, int y, int x, int size)
{
    for (int i = y;i < y + size;i++)
    {
        for (int j = x; j < x + size;j++)
        {
            if (park[i][j] != "-1")
            {
                return false;
            }
        }
    }

    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<>());
    int h = park.size();
    int w = park[0].size();
    for (auto size : mats)
    {
        for (int i = 0;i <= h - size;i++)
        {
            for (int j = 0;j <= w - size;j++)
            {
                if (park[i][j] != "-1")
                {
                    continue;
                }
                if (Check(park, i, j, size))
                {
                    return size;
                }
            }
        }
    }



    return -1;
}
int main()
{
    vector<int> mats{ 1,2};
    vector<vector<string>> park{ {"A", "-1"},{"A", "-1"} };

    int check = solution(mats, park);
    
    return 0;
}