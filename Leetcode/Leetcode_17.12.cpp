// BiNode
class Solution {
public:
    TreeNode* res = new TreeNode(0);
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root) return root;
        TreeNode* blind = res;
        dfs(root);
        return blind->right;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        root->left = nullptr;
        res->right = root;
        res = root;
        dfs(root->right);
    }
};

// 快得多
class Solution2 {
public:
    TreeNode* res = new TreeNode(0);
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root) return root;
        TreeNode* blind = res;
        dfs(root);
        return blind->right;
    }
    void dfs(TreeNode* root) {
        if(root) {
            dfs(root->left);
            root->left = nullptr;
            res->right = root;
            res = root;
            dfs(root->right);
        }
    }
};