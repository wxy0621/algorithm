// 替换所有的问号
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == '?') {
                char pre = (i == 0 ? ' ' : s[i-1]);
                char back = (i == (n - 1) ? ' ' : s[i+1]);
                char temp = 'a';
                while(pre == temp || back == temp) ++temp;
                s[i] = temp;
            }
        }
        return s;
    }
};