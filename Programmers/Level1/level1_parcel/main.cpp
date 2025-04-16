#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {

    int pLine = (n / w); // 완전히 채워진 상자들
    int md = (n % w);// 채워지지 못한 상자들
    vector<bool> pL(w);
    for (int i = 0; i < md;i++)
    {
        pL[i] = 1;
    }
    if ((pLine + (md > 0)) % 2 == 0)
    {
        reverse(pL.begin(), pL.end());
    }
    int tarLine = (num / w); // 타겟의 완전히 채워진 상자들
    int tarMd = (num % w); // 타겟의 채워지지 못한 상자들 여기서 마지막 상자가 타겟
    int tarNum{};
    bool check = (tarLine + (tarMd > 0)) % 2 == 0;
    if (tarMd != 0)
    {
        if (!check)
        {
            tarNum = tarMd -  1;
        }
        else
        {
            tarNum = w - tarMd;
        }
    }
    else
    {
        if (!check)
        {
            tarNum = w - 1;
        }
    }
    int answer = tarMd ? 0 : 1;
    answer += (pLine - tarLine);
    if (pL[tarNum])
    {
        answer++;
    }

    return answer;
}
int solution(int n, int w, int num) {
    int answer = 0;
    while (num <= n)
    {
        answer++;
        num += (w - 1 - (w + num - 1) % w) * 2 + 1;
    }
    return answer;
}
int main()
{
    solution(10, 2, 1);

}