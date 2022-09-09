// 检查平衡性
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return abs(tall(root->left) - tall(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int tall(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return max(left, right) + 1;
    }
};