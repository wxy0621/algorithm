// 完全二叉树的节点个数
class Solution {
public:
    int res = 0;
    int countNodes(TreeNode* root) {
        helper(root);
        return res;
    }
    void helper(TreeNode* root) {
        if(!root) return;
        ++res;
        helper(root->left);
        helper(root->right);
    }
};

// 快些
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};