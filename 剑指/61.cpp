// 扑克牌中的顺子
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int count_zeros = 0;
        int count_gap = 0;
        int n = nums.size();

        // 排序
        sort(nums.begin(), nums.end());

        // 求万能牌0的数量
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) count_zeros++;
        }

        // 求间隔的数量
        int small = count_zeros;
        int big = small + 1;
        while(big < n) {
            if(nums[small] == nums[big])
                return false;
            count_gap += nums[big] - nums[small] - 1;
            small = big;
            big++;
        }

        // 间隔小于等于0时，达成
        return (count_zeros >= count_gap) ? true : false;
    }
};

int main()
{
    
    return 0;
}