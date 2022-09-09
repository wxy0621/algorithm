// 连续子数组的最大和，修改或者不改原数组两种方法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int temp_max = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            temp_max = max(temp_max + nums[i], nums[i]);
            res = max(res, temp_max);
        }
        return res;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += max(0, nums[i-1]);
        }
        return *max_element(nums.begin(), nums.end());
    }
};

int main()
{
    Solution2 a;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    a.maxSubArray(nums);
    return 0;
}