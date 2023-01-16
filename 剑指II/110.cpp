// 所有路径
// dfs
class Solution {
public:
    void dfs(vector<vector<int>>& graph, int index) {
        if (index == nodeNum - 1) {
            res.emplace_back(path);
            return;
        }
        for (auto& j: graph[index]) {
            path.emplace_back(j);
            dfs(graph, j);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        nodeNum = graph.size();
        if (nodeNum == 0) return {};
        path = {0};
        dfs(graph, 0);
        return res;
    }
private:
    int nodeNum;
    vector<vector<int>> res;
    vector<int> path;
};