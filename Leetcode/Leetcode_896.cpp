// 单调数列
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag = 0;
        int n = A.size();
        for (int i = 0; i < n-1; ++i) {
            if (flag == 0) {
                if (A[i+1] < A[i]) flag = 1;
                else if (A[i+1] > A[i]) flag = 2;
            } else if (flag == 1) {
                if (A[i+1] > A[i]) return false;
            } else if (flag == 2) {
                if (A[i+1] < A[i]) return false;
            }
        }
        return true;
    }
};