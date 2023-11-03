// 省份数量
class Solution {
public:
    int findParent(int i) {
        if (parents[i] != i) {
            parents[i] = findParent(parents[i]);
        }
        return parents[i];
    }
    void unionCities(int i, int j) {
        parents[findParent(i)] = findParent(j);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n < 2) return n;
        parents.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    unionCities(i, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (parents[i] == i) ++res;
        }
        return res;
    }
private:
    vector<int> parents;
};