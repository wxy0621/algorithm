// 把二叉搜索树转换为累加树
// dfs
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        sum = 0;
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        root->val += sum;
        sum = root->val;
        dfs(root->left);
    }
private:
    int sum;
};