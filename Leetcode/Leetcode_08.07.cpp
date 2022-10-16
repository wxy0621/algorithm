// 无重复字符串的排列组合
class Solution {
public:
    void backTracking(string& S, int start) {
        if (start == n) {
            res.emplace_back(S);
            return;
        }
        for (int i = start; i < n; ++i) {
            swap(S[i], S[start]);
            backTracking(S, start + 1);
            swap(S[i], S[start]);
        }
    }
    vector<string> permutation(string S) {
        n = S.size();
        backTracking(S, 0);
        return res;
    }
private:
    vector<string> res;
    int n;
};