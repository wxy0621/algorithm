// 最长回文串
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> m;
        for(char a: s) {
            ++m[a];
        }
        for(auto p: m) {
            int v = p.second;
            res += v / 2 * 2;
            if(v % 2 == 1 && res % 2 == 0)
                ++res;
        }
        return res;
    }
};