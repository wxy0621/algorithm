// 加油站
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int curGas = 0;
        int totalGas = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            curGas += (gas[i] - cost[i]);
            totalGas += (gas[i] - cost[i]);
            if (curGas < 0) {
                curGas = 0;
                res = i + 1;
            }
        }
        return totalGas >= 0 ? res : -1;
    }
};
