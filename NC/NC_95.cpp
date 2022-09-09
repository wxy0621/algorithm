// 数组中的最长连续子序列
class Solution {
public:
    /**
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr) {
        // write code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = 1;
        int tempMax = 1;
        int lastNum = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] == lastNum) continue;
            if (arr[i] != lastNum + 1) {
                tempMax = 1;
                lastNum = arr[i];
            } else {
                ++tempMax;
                ++lastNum;
            }
            res = max(res, tempMax);
        }
        res = max(res, tempMax);
        return res;
    }
};