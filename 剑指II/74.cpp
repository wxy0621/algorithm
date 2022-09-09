// 合并区间
class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        vector< vector<int> > res;
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= right) right = max(right, intervals[i][1]);
            else {
                res.emplace_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.emplace_back(vector<int>{left, right});
        return res;
    }
};
