// 买卖股票的最佳时机 II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); ++i) {
            int dif = prices[i] - prices[i-1];
            if(dif > 0) res += dif;
        }
        return res;
    }
};