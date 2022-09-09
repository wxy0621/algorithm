// 排序数组
// 三大高级排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums;

        // 快排
        // quickSort(nums, 0, n - 1);

        // 归排
        // vector<int> temp(n);
        // mergeSort(nums, temp, 0, n - 1);

        // 堆排
        heapSort(nums);

        return nums;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int sentinel = left, i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[sentinel]) --j;
            while (i < j && nums[i] <= nums[sentinel]) ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[sentinel]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }

    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        int i = left, j = mid + 1, k = left;
        mergeSort(nums, temp, left, mid);
        mergeSort(nums, temp, mid+1, right);
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];
        for (int l = left; l <= right; ++l) nums[l] = temp[l];
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