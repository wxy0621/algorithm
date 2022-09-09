// 二叉搜索树的范围和
// dfs
class Solution {
public:
    int res = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr) return 0;
        dfs(root, L, R);
        return res;
    }

    void dfs(TreeNode* root, int L, int R) {
        if(root == nullptr) return;
        if(root->val >= L && root->val <= R) res += root->val;
        if(root->val < R) dfs(root->right, L, R);
        if(root->val > L) dfs(root->left, L, R);
    }
};