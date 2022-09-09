// 连通网络的操作次数
// 并查集
class UnionFind {
public:
    vector<int> size;
    vector<int> parent;
    int n;
    int setCount;
public:
    UnionFind(int _n): setCount(_n), n(_n), size(_n, 1), parent(_n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        --setCount;
        size[x] += size[y];
        return true;
    }

    bool isConnected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) return -1;
        UnionFind u(n);
        for (const auto& connection: connections) {
            u.unite(connection[0], connection[1]);
        }
        return u.setCount - 1;
    }
};