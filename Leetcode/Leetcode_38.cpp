// 外观数组
class Solution {
public:
    string countAndSay(int n) {
        string res = helper(n);
        return res;
    }

    string helper(int n) {
        if(n == 1) return "1";
        string res;
        string s = helper(n-1);
        int m = s.size();
        int count = 1;
        for(int i = 0; i < m; ++i) {
            if(i != m - 1 &&s[i] == s[i+1]) {
                ++count;
            } else {
                res += to_string(count) + s[i];
                count = 1;
            }
        }
        return res;
    }
};