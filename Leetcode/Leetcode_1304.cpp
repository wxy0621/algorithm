// 和为零的N个唯一整数
class Solution {
public:
    vector<int> sumZero(int n) {
        int sum = 0;
        vector<int> res;
        for(int i = 0; i < n - 1; ++i) {
            res.emplace_back(i);
            sum += i;
        }
        res.emplace_back(-sum);
        return res;
    }
};