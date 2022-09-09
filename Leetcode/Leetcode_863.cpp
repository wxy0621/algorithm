// 二叉树中所有距离为 K 的结点
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target) return {};
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> m;
        makeMap(root, nullptr, m);
        dfs(target, nullptr, res, k, m);
        return res;
    }
    void makeMap(TreeNode* root, TreeNode* father, unordered_map<TreeNode*, TreeNode*>& m) {
        if (!root) return;
        m[root] = father;
        makeMap(root->left, root, m);
        makeMap(root->right, root, m);
    }
    void dfs(TreeNode* node, TreeNode* lastNode, vector<int>& res, int k, unordered_map<TreeNode*, TreeNode*>& m) {
        if (!node) return;
        if (k == 0) res.emplace_back(node->val);
        if(node->left != lastNode) dfs(node->left, node, res, k-1, m);
        if(node->right != lastNode) dfs(node->right, node, res, k-1, m);
        if(m[node] != lastNode) dfs(m[node], node, res, k-1, m);
    }
};