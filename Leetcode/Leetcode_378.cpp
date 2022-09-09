// 有序矩阵中的第K小的元素
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(helper(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int helper(vector< vector<int> >& matrix, int mid, int k, int n) {
        int num = 0;
        int j = 0;
        int i = n - 1;
        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }
};

int main()
{
    
    return 0;
}