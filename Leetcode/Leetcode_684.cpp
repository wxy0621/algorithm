// 冗余连接
// 并查集
class Solution {
public:
    int findParent(vector<int>& parents, int i) {
        if (parents[i] != i) {
            parents[i] = findParent(parents, parents[i]);
        }
        return parents[i];
    }
    void unionNode(vector<int>& parents, int i, int j) {
        int p1 = findParent(parents, i);
        int p2 = findParent(parents, j);
        parents[p1] = p2;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1);
        for (int i = 1; i <= n; ++i) {
            parents[i] = i;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (findParent(parents, node1) != findParent(parents, node2)) {
                unionNode(parents, node1, node2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
};