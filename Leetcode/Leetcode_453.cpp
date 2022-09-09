// 最小移动次数使数组元素相等
// 数学题
// 两次遍历，避免大数问题
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int min_num = INT_MAX;
        for(auto& num: nums) {
            min_num = min(min_num, num); 
        }
        for(auto& num: nums) {
            sum += num - min_num;
        }
        return sum;
    }
};