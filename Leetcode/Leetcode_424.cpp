// 替换后的最长重复字符
// 动态维护了一个最大窗口
// 思想太 nb， 深究要累死
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0) return 0;
        int maxNumOfChar = 0;
        int left = 0, right = 0;
        vector<int> nums(26, 0);
        while (right < n) {
            ++nums[s[right] - 'A'];
            maxNumOfChar = max(maxNumOfChar, nums[s[right] - 'A']);
            if (right - left + 1 - maxNumOfChar > k) {
                --nums[s[left] - 'A'];
                ++left;
            }
            ++right;
        }
        return right - left;
    }
};