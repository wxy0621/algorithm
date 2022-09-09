// 加起来和为目标值的组合
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
        int n = num.size();
        if (n == 0) return {};
        sort(num.begin(), num.end());
        vector< vector<int> > res;
        vector<int> temp;
        dfs(num, n, res, target, 0, temp);
        return res;
    }
    void dfs(vector<int>& num, const int& n, vector< vector<int> >& res, int target, int start, vector<int>& temp) {
        if (target == 0) {
            res.emplace_back(temp);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < n; ++i) {
            if (i > start && num[i] == num[i-1]) continue;
            temp.emplace_back(num[i]);
            dfs(num, n, res, target - num[i], i + 1, temp);
            temp.pop_back();
        }
    }
};