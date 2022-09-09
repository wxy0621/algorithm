// 删除回文子序列
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0) return 0;
        string temp = s;
        reverse(temp.begin(), temp.end());
        if(temp == s) return 1;
        return 2;
    }
};