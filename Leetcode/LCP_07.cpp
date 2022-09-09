// 传递信息
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int res = 0;
        vector< vector<int> > paths(n);
        for (auto& rela: relation) paths[rela[0]].emplace_back(rela[1]);
        dfs(paths, res, k, n, 0);
        return res;
    }
    void dfs(vector< vector<int> >& paths, int& res, int k, const int& n, int nowLoc) {
        if (k < 0) return;
        if (k == 0 && nowLoc == n - 1) ++res;
        for (int i = 0; i < paths[nowLoc].size(); ++i) dfs(paths, res, k - 1, n, paths[nowLoc][i]);
    }
};