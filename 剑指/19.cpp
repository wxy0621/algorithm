// 正则表达式匹配，回溯法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
        {
            return s.empty();
        }

        // 判断第一个字符是否匹配
        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        // 若p的长度大于2，且p的第二个字符为*，则可能出现两种情况
        // 第一种：p的前两个字符无效，继续遍历p下面的两个字符
        // 第二种：s字符可以出现多次，继续遍历s后面的字符
        if(p.size() >= 2 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main()
{

    return 0;
}