// 商品折扣后的最终价格
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        int n = prices.size();
        for(int i = 0; i < n - 1; ++i) {
            bool flag = true;
            for(int j = i + 1; j < n; ++j) {
                if(prices[j] <= prices[i]) {
                    res.emplace_back(prices[i] - prices[j]);
                    flag = false;
                    break;
                }      
            }
            if(flag) res.emplace_back(prices[i]);
        }
        res.emplace_back(prices[n-1]);
        return res;
    }
};