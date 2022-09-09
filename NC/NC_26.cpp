// 括号生成
class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    int n;
    void backTracking(vector<string>& res, string cur, int l, int r) {
        if (l > n || r > n || r > l) {
            return;
        }
        if (l == n && r == n) {
            res.emplace_back(cur);
            return;
        }
        backTracking(res, cur + '(', l + 1, r);
        backTracking(res, cur + ')', l, r + 1);
    }
    vector<string> generateParenthesis(int n) {
        // write code here
        vector<string> res;
        string cur;
        this->n = n;
        backTracking(res, cur, 0, 0);
        return res;
    }
};