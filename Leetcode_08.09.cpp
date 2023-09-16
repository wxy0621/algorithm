// 括号
// backtrack
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backtrack(res, str, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string>& res, string& str, int left, int right, int n) {
        if (str.size() == n * 2) {
            res.emplace_back(str);
            return;
        }
        if (left < n) {
            str.push_back('(');
            backtrack(res, str, left + 1, right, n);
            str.pop_back();
        }
        if (left > right) {
            str.push_back(')');
            backtrack(res, str, left, right + 1, n);
            str.pop_back();
        }
    }
};