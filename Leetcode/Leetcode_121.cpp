// 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        int min_price = prices[0];
        for (int i = 1; i < n; ++i) {
            min_price = min(min_price, prices[i]);
            res = max(res, prices[i] - min_price);
        }
        return res;
    }
};