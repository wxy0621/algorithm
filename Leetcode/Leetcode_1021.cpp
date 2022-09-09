// 删除最外层的括号
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        stack<char> s;
        for (auto& c: S) {
            if (c == ')') s.pop();
            if (!s.empty()) res += c;
            if (c == '(') s.push('(');
        }
        return res;
    }
};