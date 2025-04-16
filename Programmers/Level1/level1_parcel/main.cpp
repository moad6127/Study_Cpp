#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {

    int pLine = (n / w); // ������ ä���� ���ڵ�
    int md = (n % w);// ä������ ���� ���ڵ�
    vector<bool> pL(w);
    for (int i = 0; i < md;i++)
    {
        pL[i] = 1;
    }
    if ((pLine + (md > 0)) % 2 == 0)
    {
        reverse(pL.begin(), pL.end());
    }
    int tarLine = (num / w); // Ÿ���� ������ ä���� ���ڵ�
    int tarMd = (num % w); // Ÿ���� ä������ ���� ���ڵ� ���⼭ ������ ���ڰ� Ÿ��
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