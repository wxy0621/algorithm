// 二叉树的直径
// 一定会遍历每个节点，每次都会记录 左子树+右子树 深度之和，得到的最大职黑即为直径
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res;
    }
    int helper(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};