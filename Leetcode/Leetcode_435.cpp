// 无重叠区间
// 贪心法
// 排序，然后不停地更新最右边的节点标志，求出做多的连续区间，最后做减法
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        int res = 1;

        sort(intervals.begin(), intervals.end(), cmp);

        int right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (right <= intervals[i][0]) {
                right = intervals[i][1];
                ++res;
            }
        }

        return n - res;
    }
};