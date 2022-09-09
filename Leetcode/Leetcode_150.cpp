// 逆波兰表达式求值
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res;
        int n = tokens.size();
        for(int i = 0; i < n; ++i) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(tokens[i] == "+") res = num2 + num1;
                else if(tokens[i] == "-") res = num2 - num1;
                else if(tokens[i] == "*") res = num2 * num1;
                else if(tokens[i] == "/") res = num2 / num1;
                s.push(res);
            } else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};