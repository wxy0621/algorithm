// 括号的分数
// 栈
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        stk.push(0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') stk.push(0);
            else {
                int temp = stk.top();
                stk.pop();
                stk.top() += max(temp * 2, 1);
            }
        }
        return stk.top();
    }
};