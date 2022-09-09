// 两地调度
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        int len = costs.size();
        vector<int> dif(len, 0);
        for (int i = 0; i < len; ++i) {
            res += costs[i][0];
            dif[i] = costs[i][0] - costs[i][1];
        }
        sort(dif.begin(), dif.end(), greater<int>());
        for (int i = 0; i < len / 2; ++i) {
            res -= dif[i];
        }
        return res;
    }
};
