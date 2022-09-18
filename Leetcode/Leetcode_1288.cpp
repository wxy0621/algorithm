// 删除被覆盖区间
bool cmp(vector<int>& v1, vector<int>& v2) {
    if (v1[0] == v2[0]) return v1[1] > v2[1];
    return v1[0] < v2[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int deleteInterval = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int first = intervals[0][0], second = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][1] > second) {
                first = intervals[i][0];
                second = intervals[i][1];
            } else {
                ++deleteInterval;
            }
        }
        return n - deleteInterval;
    }
};