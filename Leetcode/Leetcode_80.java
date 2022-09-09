// 删除有序数组中的重复项 II
class Solution {
    public int removeDuplicates(int[] nums) {
        int res = 1;
        int i = 1, j = 1, n = nums.length;
        int lastNum = nums[0], countNow = 1;
        while (j < n) {
            if (nums[j] == lastNum) {
                ++countNow;
                if (countNow <= 2) {
                    nums[i++] = nums[j];
                    ++countNow;
                    ++res;
                }
            } else {
                nums[i++] = nums[j];
                countNow = 1;
                lastNum = nums[j];
                ++res;
            }
            ++j;
        }
        return res;
    }
}