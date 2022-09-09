// 实现strStr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        if(j == needle.size()) return i - needle.size();
        return -1;
    }
};