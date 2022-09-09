// 有序数组的平方
// 双指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int n = A.size();
        int i = 0, j = 1;
        for(j = 0; j < n; ++j) {
            if(A[j] >= 0) {
                i = j - 1;
                break;
            }
        }
        while(i >= 0 && j < n) {
            if(abs(A[i]) >= abs(A[j])) {
                res.emplace_back(A[j] * A[j]);
                ++j;
            } else {
                res.emplace_back(A[i] * A[i]);
                --i;
            }
        }
        while(i >= 0) {
            res.emplace_back(A[i] * A[i]);
            --i;
        }
        while(j < n) {
            res.emplace_back(A[j] * A[j]);
            ++j;
        }
        return res;
    }
};

// 排序
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        for(int& num: A) {
            res.emplace_back(num * num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};