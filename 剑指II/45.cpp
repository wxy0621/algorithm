// 二叉树最底层最左边的值
// dfs
class Solution {
public:
    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
private:
    int res;
    int maxDepth;
};