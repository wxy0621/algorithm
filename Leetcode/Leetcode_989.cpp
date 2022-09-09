// 数组形式的整数加法
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int carry = 0, n = A.size();
        for(int i = n - 1; i >= 0; --i) {
            int temp = carry + A[i] + (K % 10);
            A[i] = temp % 10;
            carry = temp / 10;
            K /= 10;
        }
        carry += K;
        if(carry == 0) return A;
        while(carry != 0) {
            int temp = (carry % 10);
            carry /= 10;
            res.emplace_back(temp);
        }
        reverse(res.begin(), res.end());
        for(int i = 0; i < n; ++i) {
            res.emplace_back(A[i]);
        }
        return res;
    }
};