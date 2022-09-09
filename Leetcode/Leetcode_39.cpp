// 组合总和
// 1 和 2 几乎一样
class Solution {
public:
    vector< vector<int> > res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, {});
        return res;
    }

    void dfs(int i, vector<int>& candidates, int target, vector<int> temp) {
        if(target == 0) {
            res.emplace_back(temp);
            return;
        }
        if(i == candidates.size() || target < 0) return;
        dfs(i + 1, candidates, target, temp);
        temp.emplace_back(candidates[i]);
        dfs(i, candidates, target - candidates[i], temp);
    }
};

// 改版1
class Solution2 {
public:
    vector< vector<int> > res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, {});
        return res;
    }

    void dfs(int i, vector<int>& candidates, int target, vector<int> temp) {
        if(target == 0) {
            res.emplace_back(temp);
            return;
        }
        if(i == candidates.size() || target < 0) return;
        temp.emplace_back(candidates[i]);
        dfs(i, candidates, target - candidates[i], temp);
        temp.pop_back();
        dfs(i + 1, candidates, target, temp);
    }
};

// 改版2
class Solution3 {
public:
    vector< vector<int> > res;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return res;
    }

    void dfs(int i, vector<int>& candidates, int target) {
        if(target == 0) {
            res.emplace_back(temp);
            return;
        }
        if(i == candidates.size() || target < 0) return;
        temp.emplace_back(candidates[i]);
        dfs(i, candidates, target - candidates[i]);
        temp.pop_back();
        dfs(i + 1, candidates, target);
    }
};

// for 循环改版3
class Solution {
public:
    vector< vector<int> > res;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return res;
    }

    void dfs(int start, vector<int>& candidates, int target) {
        if(target == 0) {
            res.emplace_back(temp);
            return;
        }
        if(target < 0) return;
        for(int i = start; i < candidates.size(); ++i) {
            if(target - candidates[i] < 0) continue;
            temp.emplace_back(candidates[i]);
            dfs(i, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
};