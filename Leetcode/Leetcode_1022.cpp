// 从根到叶的二进制数之和
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int res = 0, temp = 0;
        dfs(root, res, temp);
        return res;
    }
    void dfs(TreeNode* root, int& res, int temp) {
        if(!root) return;
        temp = temp * 2 + root->val;
        if(!root->left && !root->right) {
            res += temp;
            return;
        }
        dfs(root->left, res, temp);
        dfs(root->right, res, temp);
    }
};