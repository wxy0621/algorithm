// 二叉搜索树节点最小距离
// 中序遍历
class Solution {
public:
    long long pre = INT_MIN, res = INT_MAX;
    int minDiffInBST(TreeNode* root) {
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