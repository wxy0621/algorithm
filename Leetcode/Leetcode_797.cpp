// 所有可能的路径
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(graph, temp, res, 0);
        return res;
    }
    void dfs(vector<vector<int>>& graph, vector<int>& temp, vector<vector<int>>& res, int nowNodeId) {
        if (nowNodeId == graph.size()-1) 
        {
            temp.emplace_back(nowNodeId);
            res.emplace_back(temp);
            temp.pop_back();
        }
        for (int i = 0; i < graph[nowNodeId].size(); ++i) {
            temp.emplace_back(nowNodeId);
            dfs(graph, temp, res, graph[nowNodeId][i]);
            temp.pop_back();
        }
    }
};