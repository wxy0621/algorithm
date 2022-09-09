// 不同的二叉搜索树
// 数学推导，以 i 为根节点，左子树有 i-1 个节点， 右子树有 n-i 个节点
// 可以以 1-n 为根节点，累加求和即可
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1,
        dp[1] = 1;
        for(int i = 2; i < n + 1; ++i) {
            for(int j = 1; j < i + 1; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};