// 山峰数组的顶部
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return -1;
        int maxIndex = 0;
        int maxNum = arr[0];
        for (int i = 1; i < n; ++i) {
            if (maxNum < arr[i]) {
                maxIndex = i;
                maxNum = arr[i];
            }
        }
        return maxIndex;
    }
};

// 二分
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 1, j = n - 2;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid] > arr[mid-1]) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }
};