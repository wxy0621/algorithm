// 最富有客户的资产总量
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto& account: accounts) {
            int tempTotal = 0;
            for (auto& num: account) tempTotal += num;
            res = max(res, tempTotal);
        }
        return res;
    }
};