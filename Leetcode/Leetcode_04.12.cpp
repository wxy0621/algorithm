// 求和路径
class Solution {
public:
    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        int ret = 0;
        if (sum - root->val == 0) {
            ret = 1;
        }
        return ret + dfs(root->left, sum-root->val) + dfs(root->right, sum-root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};