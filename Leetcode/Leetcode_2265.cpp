// 统计值等于子树平均值的节点数
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        if (!root) return 0;
        count = 0;
        res = 0;
        dfs(root);
        return res;
    }
private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int farther = count;
        ++count;
        int val = dfs(root->left) + dfs(root->right) + root->val;
        if (val / (count - farther) == root->val) ++res;
        return val;
    }
    int count;
    int res;
};