// 买卖股票的最佳时机 III
// 状态机 * 5 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int sell1 = INT_MIN;
        int sell2 = INT_MIN;
        int buy1 = INT_MIN;
        int buy2 = INT_MIN;
        for (int i = 0; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};