// 主要元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        for (auto& num: nums) {
            if (count == 0) {
                candidate = num;
            }
            if (candidate == num) ++count;
            else --count;
        }
        count = 0;
        for (auto& num: nums) {
            if (num == candidate) ++count;
        }
        return nums.size() < count * 2 ? candidate : -1;
    }
};