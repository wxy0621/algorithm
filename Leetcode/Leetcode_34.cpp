// 在排序数组中查找元素的第一个和最后一个位置
#include <bits/stdc++.h>

using namespace std;

// 顺序遍历，暴力法
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target && res[0] == -1) {
                res[0] = i;
                res[1] = i;
            }
            if(nums[i] == target && res[0] != -1) {
                res[1] = i;
            }
        }
        return res;
    }
};

// 二分法
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        res[0] = searchStart(nums, target);
        res[1] = searchEnd(nums, target);
        return res;
    }

    int searchStart(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m, res1 = -1;
        while(i <= j) {
            m = (i + j) >> 1;
            if(nums[m] == target) {
                res1 = m;
                j = m - 1;
            } else if(nums[m] > target) {
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
        return res1;
    }

    int searchEnd(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m, res2 = -1;
        while(i <= j) {
            m = (i + j) >> 1;
            if(nums[m] == target) {
                res2 = m;
                i = m + 1;
            } else if(nums[m] > target) {
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
        return res2;
    }
};

int main()
{
    
    return 0;
}