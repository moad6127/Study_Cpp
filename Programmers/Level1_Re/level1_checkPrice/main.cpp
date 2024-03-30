using namespace std;

long long solution(int price, int money, int count)
{
    long long answer{};
    for (long long i = 1; i <= count ; i++)
    {
        answer += price * i;
    }
    if (money - answer >= 0)
    {
        return 0;
    }
    else
    {
        return -1 * (money - answer);
    }
}