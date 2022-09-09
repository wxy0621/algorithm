// 二叉搜索树的最小绝对差
// 中序遍历，轮番比较差值
class Solution {
public:
    long long pre = INT_MIN, res = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        res = min(res, root->val - pre);
        pre = root->val;
        inorder(root->right);
    }
};