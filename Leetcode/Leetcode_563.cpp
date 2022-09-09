// 二叉树的坡度
class Solution {
public:
    int res = 0;
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res += abs(left - right);
        return left + right + root->val;
    }
};