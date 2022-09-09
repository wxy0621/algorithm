// 二叉树的最大深度
// 慢一些
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 速度快
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = 0, right = 0;
        if(root->left) left = dfs(root->left);
        if(root->right) right = dfs(root->right);
        return 1 + max(left, right);
    }
};

class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        depth = max(depth, maxDepth(root->left));
        depth = max(depth, maxDepth(root->right));
        return depth + 1;
    }
};