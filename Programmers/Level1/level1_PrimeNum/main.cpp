#include <string>
#include <vector>

using namespace std;

//�Ҽ� = 1�� �ڱ��ڽ����θ� ������ �ִ� ��
bool Prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (!(n % i))
        {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        if (Prime(i))
        {
            answer++;
        }
    }
    return answer;
}