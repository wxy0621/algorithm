// 提莫攻击
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 0) return 0;
        int res = duration;
        for(int i = 1; i < n; ++i) {
            res += duration;
            if(timeSeries[i] < timeSeries[i - 1] + duration) res -= (timeSeries[i - 1] + duration - timeSeries[i]);
        }
        return res;
    }
};