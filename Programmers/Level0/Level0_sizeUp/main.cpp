
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            string s;
            for (int x = 0; x < picture[i].size(); x++)
            {
                for (int y = 0; y < k; y++)
                {
                    s += picture[i][x];
                }
            }
            answer.push_back(s);
        }
    }
    return answer;
}
int main()
{
    vector<string> pic{".xx...xx.", "x..x.x..x", "x...x...x", ".x.....x.", "..x...x..", "...x.x...", "....x...."};
    vector<string> ans = solution(pic, 2);
    for (auto e : ans)
    {
        cout << e << '\n';
    }
}