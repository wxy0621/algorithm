// 拼车
// 差分
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001, 0);
        int maxRoad = INT_MIN;
        for (int i = 0; i < trips.size(); ++i) {
            road[trips[i][1]] += trips[i][0];
            road[trips[i][2]] -= trips[i][0];
            maxRoad = max(maxRoad, trips[i][2]);
        }
        int totalPassager = 0;
        for (int i = 0; i <= maxRoad; ++i) {
            totalPassager += road[i];
            if (totalPassager > capacity) return false;
        }
        return true;
    }
};