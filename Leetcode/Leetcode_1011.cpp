// 在 D 天内送达包裹的能力
// 二分法
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            int needs = 1;
            int cur = 0;
            for (auto& weight: weights) {
                if (cur + weight > mid) {
                    ++needs;
                    cur = 0;
                }
                cur += weight;
            }
            if (needs <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};