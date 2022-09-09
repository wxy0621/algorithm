// 判断二分图
// dfs 三色标记法
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i) {
        if (flag[i] == 0) {
            flag[i] = 1;
        }
        int m = graph[i].size();
        for (int j = 0; j < m; ++j) {
            bool visited = true;
            if (flag[graph[i][j]] == 0) visited = false;
            if (flag[i] == 1) {
                if (flag[graph[i][j]] == 1) return false;
                flag[graph[i][j]] = 2;
            } else {
                if (flag[graph[i][j]] == 2) return false;
                flag[graph[i][j]] = 1;
            }
            if (!visited) {
                if (!dfs(graph, graph[i][j])) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        if (n < 3) return true;
        flag.resize(n);
        for (int i = 0; i < n; ++i) {
            if (flag[i] == 0) {
                if (!dfs(graph, i)) return false;
            }
        }
        return true;
    }
private:
    int n;
    vector<int> flag;
};