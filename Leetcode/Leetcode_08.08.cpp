// 有重复字符串的排列组合
// 回溯
class Solution {
public:
    void backTracking(string S, int index) {
        if (index == n - 1) {
            res.emplace_back(S);
            return;
        }
        for (int i = index; i < n; ++i) {
            if (i != index && S[i] == S[index]) continue;
            swap(S[i], S[index]);
            backTracking(S, index + 1);
        }
    }
    vector<string> permutation(string S) {
        n = S.size();
        if (n == 0) return {};
        sort(S.begin(), S.end());
        backTracking(S, 0);
        return res;
    }
private:
    vector<string> res;
    int n;
};