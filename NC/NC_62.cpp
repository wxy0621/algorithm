// 平衡二叉树
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return helper(pRoot) != -1;
    }
    int helper(TreeNode* node) {
        if (!node) return 0;
        int left = helper(node->left);
        if (left == -1) return -1;
        int right = helper(node->right);
        if (right == -1) return -1;
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};