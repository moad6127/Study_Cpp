#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int w{ 3 };
    while (true)
    {
        int h{ 3 };
        while (true)
        {
            if (w < h)
            {
                break;
            }
            int MAX = w * h;
            int br = (w * 2) + ((h * 2) - 4);
            int ye = MAX - br;
            if (br == brown && ye == yellow)
            {
                return{ w,h };
            }
            h++;
        }
        w++;
    }
    return answer;
}