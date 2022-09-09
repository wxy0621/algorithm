// 0 ~ n-1 中缺失的数字
// 二分搜索
// 分为左右两个数组，i可以得到右数组的第一值得索引，j可以得到左数组的最后一个值得索引
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] == m)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

int main()
{

    return 0;
}