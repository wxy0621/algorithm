// 反转字符串 II
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += 2 * k) {
            int j = min((int)(s.size() - 1), i + k - 1);
            if(i < j) reverse(s.begin() + i, s.begin() + j + 1);
        }
        return s;
    }
};