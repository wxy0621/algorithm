// 计数二进制子串
// cur 记录当前连续的 0 / 1 个数，pre 记录当前连续的 1 / 0 个数
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int pre = 0, cur = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i - 1] == s[i]) ++cur;
            else {
                pre = cur;
                cur = 1;
            }
            if(pre >= cur) ++res; // 核心步骤
        }
        return res;
    }
};