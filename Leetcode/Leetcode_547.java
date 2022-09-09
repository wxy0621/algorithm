// 省份数量
// dfs
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int res = 0;
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, n, i);
                ++res;
            }
           
        }
        return res;
    }
    public void dfs(int[][] isConnected, boolean[] visited, int n, int i) {
        for (int j = 0; j < n; ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, n, j);
            }
        }
    }
}

// 并查集
class Solution2 {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int[] parent = new int[n];
        int res = 0;
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) union(parent, i, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) ++res;
        }
        return res;
    }
    public void union(int[] parent, int childNode, int parNode) {
        parent[find(parent, childNode)] = find(parent, parNode);  // 对根节点进行匹配
    }
    public int find(int[] parent, int index) {  // 找到集合的根节点，只有根节点的键值相等
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }
}