// 拿硬币
class Solution {
public:
    int minCount(vector<int>& coins) {
        int sum = 0;
        for (auto& coin: coins) {
            if (coin % 2 == 0) sum += coin / 2;
            else sum += (coin / 2 + 1);
        }
        return sum;
    }
};