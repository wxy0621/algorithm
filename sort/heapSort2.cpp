// 堆排序简约版
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums;

        // 堆排
        heapSort(nums);

        return nums;
    }

    void heapSort(vector<int>& nums) {
        int size = nums.size();
        for (int i = size / 2 - 1; i >= 0; --i) adjust(nums, i, size);
        for (int i = size - 1; i >= 1; --i) {
            swap(nums[i], nums[0]);
            adjust(nums, 0, i);
        }
    }
    void adjust(vector<int>& nums, int index, int size) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        int maxIndex = index;
        if (left < size && nums[left] > nums[maxIndex]) maxIndex= left;
        if (right < size && nums[right] > nums[maxIndex]) maxIndex= right;

        if (index != maxIndex) {
            swap(nums[index], nums[maxIndex]);
            adjust(nums, maxIndex, size);
        }
    }
};