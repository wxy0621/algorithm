// 对称的二叉树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return false;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return helper(left->right, right->left) && helper(left->left, right->right);
    }
};