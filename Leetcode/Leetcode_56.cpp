// 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return {};
        vector< vector<int> > res;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            if(res.size() == 0 || res.back()[1] < left) {
                res.push_back({left, right});
            } else {
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }
};