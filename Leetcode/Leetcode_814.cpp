// 二叉树剪枝
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && !root->val) return nullptr;
        return root;
    }
};