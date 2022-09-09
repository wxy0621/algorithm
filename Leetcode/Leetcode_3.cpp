// 无重复字符的最长子串
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res = 0;
        // j为滑动窗口左侧。i为滑动窗口右侧
        int j = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(m.find(s[i]) != m.end()) {
                j = max(j, m[s[i]] + 1);
            }
            m[s[i]] = i;
            res = max(res, i - j + 1);
        }
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex[128];
        for (int i = 0; i < 128; ++i) lastIndex[i] = -1;
        int res = 0;
        int start = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            start = max(start, lastIndex[s[i]] + 1);
            res = max(res, i - start + 1);
            lastIndex[s[i]] = i;
        }
        return res;
    }
};