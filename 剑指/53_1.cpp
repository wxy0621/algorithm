// 在排序数组中查找数字
// 二分搜索
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target) - helper(nums, target-1);
    }
    // helper函数查找 target 值在 nums 中的右边界（比target大的值）的索引值
    int helper(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int m;
        while(i <= j) {
            m = (i + j) / 2;
            if(nums[m] <= target)
                i = m + 1;
            else
                j = m - 1; // 之所以是 j = m - 1 因为最后返回值为 i 才是右边界，如果出现 i = j 时还会再执行一遍循环，这样i就会再 + 1，即使此时 j 的位置的值等于 target 也没关系，i 所在的位置的值会大于 target 的。
        }
        return i;
    }
};

int main()
{

    return 0;
}