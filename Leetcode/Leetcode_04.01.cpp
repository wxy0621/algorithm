// 节点间通路
class Solution {
public:
    int dfs(int start, int end) {
        if (start == end) return true;
        if (m.count(end)) {
            return dfs(start, m[end]);
        }
        return false;
    }
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        for (auto& t: graph) {
            m[t[1]] = t[0];
        }
        return dfs(start, target);
    }
private:
    unordered_map<int, int> m;
};