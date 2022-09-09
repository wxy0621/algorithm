// 翻转字符串
#include <bits/stdc++.h>

using namespace std;

string ReverseSentence(string str) {
    if(str.empty()) return str;
    int i = 0, j = str.size();
    while(i < j && str[i] == ' ') ++i;
    if(i == j) return str;

    istringstream ss(str);
    vector<string> res;
    string temp;
    while(ss >> temp)
        res.push_back(temp);
    reverse(res.begin(), res.end());
    ostringstream ret;
    for(int i = 0; i < res.size() - 1; ++i) {
        ret << res[i] << " ";
    }
    ret << res.back();

    return ret.str();
}

int main()
{
    
    return 0;
}