// 括号
// DFS
class Solution {
public:
    void dfs(int left, int right, string str) {
        if (left == 0 && right == 0) {
            res.emplace_back(str);
            return;
        }
        if (left > 0) dfs(left-1, right, str+'(');
        if (right > left) dfs(left, right-1, str+')');
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        string str = "";
        dfs(n, n, str);
        return res;
    }
private:
    vector<string> res;
};