// 最小差值 I
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxNum = *max_element(A.begin(), A.end());
        int minNum = *min_element(A.begin(), A.end());
        return maxNum - minNum > 2 * K ? maxNum - minNum - 2 * K : 0;
    }
};