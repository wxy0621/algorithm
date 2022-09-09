// 访问所有点的最小时间
// 数学
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 1; i < n; ++i) {
            int t1 = abs(points[i][0] - points[i - 1][0]);
            int t2 = abs(points[i][1] - points[i - 1][1]);
            res += max(t1, t2);
        }
        return res;
    }
};