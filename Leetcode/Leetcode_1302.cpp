// 层数最深叶子节点的和
class Solution {
public:
    int res = 0, maxdepth = 1;
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 1);
        return res;
    }
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth == maxdepth) {
            res += node->val;
        } else if (depth > maxdepth) {
            res = node->val;
            maxdepth = depth;
        }
        if (node->left) dfs(node->left, depth+1);
        if (node->right) dfs(node->right, depth+1);
    }
};