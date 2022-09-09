// 二叉树中是否存在节点和为指定值的路径
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if (!root || sum == 0) return false;
        return dfs(root, sum);
    }
    bool dfs(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        return dfs(root->left, sum - root->val) || dfs(root->right, sum - root->val);
    }
};