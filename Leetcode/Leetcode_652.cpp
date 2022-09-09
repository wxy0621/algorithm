// 寻找重复的子树
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> res;
        unordered_map<string, int> um;
        dfs(root, res, um);
        return res;
    }
    string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& um) {
        if (!root) return "";
        string str = to_string(root->val) + "," + dfs(root->left, res, um) + "," + dfs(root->right, res, um);
        if (um[str] == 1) res.emplace_back(root);
        ++um[str];
        return str;
    }
};
