// 股票的最大利润
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        int temp_min = prices[0];
        int res = prices[1] - temp_min;
        for(int i = 2; i < n; ++i) {
            // 买入价格的遍历为0-n-2；卖出价格的遍历为1-n-1;
            // 每次遍历都保存历史最小值，并且计算该次遍历卖出价格和最小值得差，并和历史最低值比较
            temp_min = min(temp_min, prices[i-1]);
            int temp = prices[i] - temp_min;
            res = max(temp, res);
        }
        return res >= 0 ? res : 0;
    }
};

int main()
{
    return 0;
}