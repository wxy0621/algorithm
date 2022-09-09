// 二叉树的所有路径和
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int sumNumbers(TreeNode* root) {
        // write code here
        if (!root) return 0;
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode* root, int& res, int tempRes) {
        if (!root) return;
        tempRes = tempRes * 10 + root->val;
        if (!root->left && !root->right) res += tempRes;
        dfs(root->left, res, tempRes);
        dfs(root->right, res, tempRes);
    }
};