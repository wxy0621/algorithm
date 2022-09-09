// 找到最终的安全状态
// 三色标记法
// 0未经过节点；1正路过节点；已遍历节点且不存在环
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int i) {
        if (color[i] > 0) return color[i] == 2;
        color[i] = 1;
        int sizeOfNode = graph[i].size();
        for (int j = 0; j < sizeOfNode; ++j) {
            if (!dfs(graph, color, graph[i][j])) return false;
        }
        color[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return {};
        vector<int> color(n, 0);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, color, i)) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};