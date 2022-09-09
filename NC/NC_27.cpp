// 集合的所有子集
class Solution {
public:
    void backTracking(vector<int>& S, vector<vector<int> >& res, const int& n, vector<int> temp, int start) {
        res.emplace_back(temp);
        for (int i = start; i < n; ++i) {
            temp.emplace_back(S[i]);
            backTracking(S, res, n, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int>& S) {
        int n = S.size();
        if (n == 0) return {};
        vector<vector<int> > res;
        vector<int> temp;
        backTracking(S, res, n, temp, 0);
        return res;
    }
};