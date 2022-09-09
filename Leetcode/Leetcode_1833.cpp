// 雪糕的最大数量
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (auto& cost: costs) {
            coins -= cost;
            if (coins < 0) break;
            ++res;
        }
        return res;
    }
};