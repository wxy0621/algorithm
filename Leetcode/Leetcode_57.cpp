// 插入区间
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector< vector<int> > res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            if (intervals[i][0] > newInterval[0] || (intervals[i][0] == newInterval[0] && intervals[i][1] >= newInterval[1])) {
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
        }
        if (intervals.size() == n) intervals.emplace_back(newInterval);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < n + 1; ++i) {
            if (right < intervals[i][0]) {
                res.emplace_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            right = max(right, intervals[i][1]);
        }
        res.emplace_back(vector<int>{left, right});
        return res;
    }
};