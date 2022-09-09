// 简化路径
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        int n = path.size();
        stack<string> stk;
        bool startSplit = false;
        string tempStr;
        for (int i = 0; i < n; ++i) {
            if (startSplit) {
                startSplit = true;
                continue;
            }
            if (path[i] == '/') {
                if (tempStr != "") stk.push(tempStr);
                tempStr = "";
            } else {
                tempStr += path[i];
            }
        }
        if (tempStr != "") stk.push(tempStr);

        stack<string> newStk;
        while (!stk.empty()) {
            newStk.push(stk.top());
            stk.pop();
        }
        while (!newStk.empty()) {
            if (newStk.top() == "..") {
                if (!stk.empty()) stk.pop();
            } else if (newStk.top() != ".") {
                stk.push(newStk.top());
            }
            newStk.pop();
        }
        while (!stk.empty()) {
            newStk.push(stk.top());
            stk.pop();
        }
        if (newStk.empty()) {
            res = "/";
        } else {
            while (!newStk.empty()) {
                res += "/";
                res += newStk.top();
                newStk.pop();
            }
        }
        return res;
    }
};