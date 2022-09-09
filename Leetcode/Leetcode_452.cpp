// 用最少数量的箭引爆气球
bool Compare(vector<int>& p1, vector<int>& p2) {
    return p1[1] < p2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        int res = 1;
        sort(points.begin(), points.end(), Compare);
        int end = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (end < points[i][0]) {
                end = points[i][1];
                ++res;
            }
        }
        return res;
    }
};