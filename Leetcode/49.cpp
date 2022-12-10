// 从根节点到叶节点的路径数字之和
// dfs
class Solution {
public:
    void dfs(TreeNode* root, int temp) {
        if (!root) return;
        temp = temp * 10 + root->val;
        if (!root->left && !root->right) {
            res += temp;
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        res = 0;
        dfs(root, 0);
        return res;
    }
private:
    int res;
};