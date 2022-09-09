// 祖父节点值为偶数的节点和
class Solution {
public:
    int res = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* node) {
        if (!node) return;
        if (node->val % 2 == 0) {
            if (node->left) {
                if (node->left->left) res += node->left->left->val;
                if (node->left->right) res += node->left->right->val;
            }
            if (node->right) {
                if (node->right->left) res += node->right->left->val;
                if (node->right->right) res += node->right->right->val;
            }
        }
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
    }
};
