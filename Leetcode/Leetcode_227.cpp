// 基本计算器 II
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int n = s.size();
        stack<int> stk;
        int num = 0;
        char flag = '+';
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } 
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                if (flag == '+') stk.push(num);
                else if (flag == '-') stk.push(-num);
                else if (flag == '*') stk.top() *= num;
                else if (flag == '/') stk.top() /= num;
                flag = s[i];
                num = 0;
            }
        }
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};