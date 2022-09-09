// 字符串变形
class Solution {
public:
    string trans(string s, int n) {
        // write code here
        string res = "";
        string temp = "";
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                res += temp;
                res += ' ';
                temp = "";
            } else if ('a' <= s[i] && s[i] <= 'z') {
                char c = toupper(s[i]);
                temp = c + temp;
            } else {
                char c = tolower(s[i]);
                temp = c + temp;
            }
        }
        res += temp;
        return res;
    }
};