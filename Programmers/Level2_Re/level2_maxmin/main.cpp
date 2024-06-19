#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss;
    ss.str(s);
    string temp;
    vector<int> vs;
    while (ss >> temp)
    {
        vs.push_back(stoi(temp));
    }
    sort(vs.begin(), vs.end());
    answer = to_string(vs.front()) + " " + to_string(vs.back());
    return answer;
}