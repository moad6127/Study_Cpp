#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    string aHead;
    for (auto e : a)
    {
        if (e >= '0' && e <= '9')
        {
            break;
        }
        aHead += toupper(e);
    }
    a = a.substr(aHead.size());
    string bHead;
    for (auto e : b)
    {
        if (e >= '0' && e <= '9')
        {
            break;
        }
        bHead += toupper(e);
    }
    b = b.substr(bHead.size());
    if (aHead != bHead)
    {
        return aHead < bHead;
    }
    string aNum;
    for (auto e : a)
    {
        if (e < '0' || e>'9')
        {
            break;
        }
        aNum += e;
    }
    string bNum;
    for (auto e : b)
    {
        if (e < '0' || e>'9')
        {
            break;
        }
        bNum += e;
    }
    return stoi(aNum) < stoi(bNum);
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), comp);
    return files;
}
int main()
{
    solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
}