// 节点与其祖先之间的最大差值
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int max_num = INT_MIN, min_num = INT_MAX;
        return dfs(root, max_num, min_num);;
    }
    int dfs(TreeNode* root, int max_num, int min_num) {
        if (!root) return max_num - min_num;
        max_num = max(max_num, root->val);
        min_num = min(min_num, root->val);
        return max(dfs(root->left, max_num, min_num), dfs(root->right, max_num, min_num));
    }
};