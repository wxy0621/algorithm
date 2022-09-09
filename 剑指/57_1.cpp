// 和为s的数字，双指针
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> res;
        while(i < j) {
            int temp = nums[i] + nums[j];
            if(temp == target) {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                return res;
            } else if(temp > target) {
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}