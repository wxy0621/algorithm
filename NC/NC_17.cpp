// 最长回文子串
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int temp1 = getRes(A, i, i, n);
            int temp2 = getRes(A, i, i + 1, n);
            res = max(res, temp2);
            res = max(res, temp1);
        }
        return res;
    }
    int getRes(const string& A, int i, int j, const int& n) {
        while (i >= 0 && j < n && A[i] == A[j]) {
            --i;
            ++j;
        }
        return j - i - 1;
    }
};