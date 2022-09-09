// 不同路径II
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrsid[0][0] == 1) return 0;
        vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j) {
                if(i == 1 && j == 1) dp[i][j] = 1;
                else {
                    if(obstacleGrid[i-1][j-1] == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() 
{
    vector< vector<int> > nums = {{1,2}};
    Solution A = new Solution();
    int t = A.uniquePathsWithObstacles(nums);
    cout << t << endl;
    return 0;
}