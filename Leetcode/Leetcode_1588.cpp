// 所有奇数长度子数组的和
// math
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int leftCount = i, rightCount = n - 1 - i;
            int leftOdd = leftCount / 2 + 1;
            int rightOdd = rightCount / 2 + 1;
            int leftEven = (leftCount + 1) / 2;
            int rightEven = (rightCount + 1) / 2;
            res += (leftOdd * rightOdd + leftEven * rightEven) * arr[i];
        }
        return res;
    }
};