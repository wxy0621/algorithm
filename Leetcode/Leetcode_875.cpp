// 爱吃香蕉的珂珂
// 二分法
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (auto& pile: piles) {
            high = max(high, pile);
        }
        int k = high;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int time = getTime(piles, mid);
            if (time <= h) {
                k = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return k;
    }
    int getTime(vector<int>& piles, int speed) {
        int time = 0;
        for (auto& pile: piles) {
            time += (pile + speed - 1 ) / speed;
        }
        return time;
    }
};