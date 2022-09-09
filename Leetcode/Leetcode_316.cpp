// 去除重复字母
// 栈
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        char m[26] = {0};
        for (auto& c: s) ++m[c-'a'];
        stack<char> stk;
        bool hasChar[26] = {false};
        for (auto& c: s) {
            if (!hasChar[c-'a']) {
                while (!stk.empty() && stk.top() > c && m[stk.top()-'a'] != 0) {
                    hasChar[stk.top()-'a'] = false;
                    stk.pop();
                }
                stk.push(c);
                hasChar[c-'a'] = true;
            }
            --m[c-'a'];
        }
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};