// 数组中的逆序对
// 归并排序，方法1超时，方法2和方法1一致，但不超时
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return res;
    }

    void mergesort(vector<int>& nums, int left, int right) {
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int n = nums.size();
        vector<int> temp(n, 0);
        int i = left, j = mid + 1, k = left, l = left;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
                res += mid + 1 - i;
            }
        }
        while(i <= mid) {
            temp[k++] = nums[i++];
        }
        while(j <= right)
            temp[k++] = nums[j++];
        while(l <= right)
            nums[l++] = temp[l++];
    }
};

class Solution2 {
public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergesort(nums, temp, 0, n - 1);
    }

    int mergesort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if(left >= right) return 0;

        int mid = (left + right) / 2;
        int n = nums.size();
        int res = mergesort(nums, temp, left, mid) + mergesort(nums, temp, mid + 1, right);
        int i = left, j = mid + 1, k = left;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
                res += mid + 1 - i;
            }
        }
        while(i <= mid) {
            temp[k++] = nums[i++];
        }
        while(j <= right)
            temp[k++] = nums[j++];
        for(int l = left; l <= right; ++l)
            nums[l] = temp[l];
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {7, 5, 6, 4};
    int res = a.reversePairs(nums);
    cout << res << endl;
    return 0;
}