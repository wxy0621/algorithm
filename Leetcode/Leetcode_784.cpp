// 字母大小写全排列
// 递归
class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return res;
    }

    void dfs(string S, int index) {
        if(index == S.size()) {
            res.emplace_back(S);
            return;
        }

        dfs(S, index + 1);
        if(isalpha(S[index])) {
            S[index] ^= 32;
            dfs(S, index + 1);
        }
    }
};