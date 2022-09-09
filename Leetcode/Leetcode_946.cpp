// 验证栈序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        int i = 0, j = 0;
        while (i < n) {
            if (s.size() == 0 || s.top() != popped[i]) {
                if (j == n) return false;
                s.push(pushed[j++]);
            } else {
                s.pop();
                ++i;
            }
        }
        return true;
    }
};