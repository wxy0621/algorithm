// 供暖器
// 二分
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int m = heaters.size();
        for (int i = 0; i < n; ++i) {
            int distance;
            if (houses[i] <= heaters[0]) {
                distance = heaters[0] - houses[i];
            } else if (houses[i] >= heaters[m-1]) {
                distance = houses[i] - heaters[m-1];
            } else {
                int left = 0;
                int right = m - 1;
                while (left < right) {
                    int mid = (right + left) >> 1;
                    if (heaters[mid] < houses[i]) left = mid + 1;
                    else right = mid;
                }
                distance = min(houses[i] - heaters[left-1], heaters[left] - houses[i]);
            }
            res = max(res, distance);
        }
        return res;
    }
};