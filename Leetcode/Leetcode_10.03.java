// 搜索旋转数组
class Solution {
    public int search(int[] arr, int target) {
        int n = arr.length;
        int i = 0, j = n - 1;
        int mid;
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (arr[i] == target) return i;
            if (arr[mid] == target) {
                while (mid > 0 && arr[mid] == arr[mid-1]) --mid;
                return mid;
            }
            if (arr[i] == arr[mid] && arr[mid] == arr[j]) {
                ++i;
                --j;
                continue;
            }
            if (arr[i] <= arr[mid]) {
                if (arr[i] <= target && target < arr[mid]) j = mid - 1;
                else i = mid + 1;
            } else {
                if (arr[mid] < target && target <= arr[j]) i = mid + 1;
                else j = mid - 1;
            }
        }
        return -1;
    }
}