// 将字符串翻转到单调递增
// dp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int count = 0;
        int dp = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++count;
            } else {
                dp = min(dp + 1, count);
            }
        }
        return dp;
    }
};