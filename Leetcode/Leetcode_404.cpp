// 左叶子之和
class Solution {
public:
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            res += root->left->val;
        dfs(root->left);
        dfs(root->right);
    }
};