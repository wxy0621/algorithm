// 航班预订统计
// 差分，降低时间复杂度
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        if (n == 0) return {};
        vector<int> res(n, 0);
        int m = bookings.size();
        if (m == 0) return res;
        for (int i = 0; i < m; ++i) {
            res[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n) {
                res[bookings[i][1]] -= bookings[i][2];
            }
        }
        for (int i = 1; i < n; ++i) {
            res[i] += res[i-1];
        }
        return res;
    }
};