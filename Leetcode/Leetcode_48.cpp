// 旋转图像
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 转置
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 反转
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};

int main()
{
    return 0;
}