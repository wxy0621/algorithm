// 全排列
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > res;
        helper(res, nums, 0, nums.size());
        return res;
    }

    void helper(vector< vector<int> >& res, vector<int>& nums, int first, int len) {
        if(first == len) {
            res.emplace_back(nums);
            return;
        }

        for(int i = first; i < len; ++i) {
            swap(nums[i], nums[first]);
            helper(res, nums, first + 1, len);
            swap(nums[i], nums[first]);
        }
    }
};

int main()
{
    
    return 0;
}