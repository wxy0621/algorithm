// 有效的山脉数组
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        bool flag = 0, mount = 0;
        for(int i = 1; i < n; ++i) {
            if(!flag) {
                if(A[i - 1] == A[i]) return false;
                else if(A[i - 1] > A[i]) flag = 1;
                else mount = 1;
            }
            if(flag) {
                if(A[i - 1] <= A[i]) return false;
            }
        }
        return mount == 1 && flag == 1;
    }
};