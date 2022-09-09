// 大餐计数
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int res = 0;
        int maxNum = 2 * *max_element(deliciousness.begin(), deliciousness.end());
        int MAXNUM = 1000000007;
        unordered_map<int, int> um;
        for (auto& delicious: deliciousness) {
            for (int i = 1; i <= maxNum; i *= 2) {
                int count = um.count(i - delicious) ? um[i - delicious] : 0;
                res = (res + count) % MAXNUM;
            }
            ++um[delicious];
        }
        return res;
    }
};