// 二叉树的堂兄弟节点
class Solution {
public:
    unordered_map<int, int> depth;
    unordered_map<int, TreeNode*> parent;
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        dfs(root, nullptr);
        return depth[x] == depth[y] && parent[x] != parent[y];
    }
    void dfs(TreeNode* root, TreeNode* par) {
        if(!root) return;
        parent[root->val] = par;
        depth[root->val] = par ? depth[par->val] + 1 : 0;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};