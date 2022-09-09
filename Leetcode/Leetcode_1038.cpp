// 把二叉搜索树转换为累加树
class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return root;
        dfs(root);
        return root;
    }
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }
};