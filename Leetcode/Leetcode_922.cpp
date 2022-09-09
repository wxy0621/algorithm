// 按奇偶排序数组 II
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        for(int i = 0; i < A.size(); i += 2) {
            if(A[i] % 2 == 1) {
                while(A[j] % 2 == 1) j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};