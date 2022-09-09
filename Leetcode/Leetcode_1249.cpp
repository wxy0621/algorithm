// 移除无效的括号
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int n = s.size();
        stack<int> stk;
        unordered_set<int> removeSetIndex;
        for (int i = 0; i < n; ++i) {
            if (isalpha(s[i])) continue;
            if (s[i] == '(') {
                stk.push(i);
            } else if (stk.empty()) {
                removeSetIndex.insert(i);
            } else {
                stk.pop();
            }
        }
        while (!stk.empty()) {
            removeSetIndex.insert(stk.top());
            stk.pop();
        }
        for (int i = 0; i < n; ++i) {
            if (isalpha(s[i])) {
                res += s[i];
                continue;
            }
            if (!removeSetIndex.count(i)) {
                res += s[i];
            }
        }
        return res;
    }
};