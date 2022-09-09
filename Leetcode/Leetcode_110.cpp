// 平衡二叉树
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return abs(helper(root->left) - helper(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    int helper(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(helper(root->left), helper(root->right));
    }
};