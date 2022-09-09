// 左旋转字符串
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        n %= s.size();
        return s.substr(n) + s.substr(0, n);
    }
};

int main()
{
    string s = "abcdefg";
    cout << (s+s).substr(1, 3) << endl;
    return 0;
}