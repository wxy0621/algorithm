// 统计二叉树中好节点的数目
// dfs
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        res = 0;
        dfs(root, INT_MIN);
        return res;
    }
    void dfs(TreeNode* root, int maxNum) {
        if (!root) return;
        if (maxNum <= root->val) ++res;
        if (root->left) dfs(root->left, max(maxNum, root->val));
        if (root->right) dfs(root->right, max(maxNum, root->val));
    }
private:
    int res;
};