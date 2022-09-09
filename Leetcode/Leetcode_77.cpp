// 组合
// 经典回溯法
class Solution {
public:
    vector< vector<int> > res;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k) {
        Backtracking(1, n, k);
        return res;
    }

    void Backtracking(int start, int n, int k) {
        if(k == 0) {
            res.emplace_back(temp);
            return;
        }
        for(int i = start; i <= n; ++i) {
            temp.emplace_back(i);
            Backtracking(i + 1, n, --k);
            ++k;
            temp.pop_back();
        }
    }
};