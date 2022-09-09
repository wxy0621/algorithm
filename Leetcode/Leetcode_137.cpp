// 只出现一次的数字 II
// 位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first = 0, second = 0;
        for(auto& num: nums) {
            first = ~second & (first ^ num);
            second = ~first & (second ^ num);
        }
        return first;
    }
};