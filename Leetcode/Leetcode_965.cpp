// 单值二叉树
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;

        return helper(root, root->val);
    }
    bool helper(TreeNode* root, int val) {
        if(root == nullptr) return true;
        if(root->val != val) return false;
        return helper(root->left, val) && helper(root->right, val);
    }
};