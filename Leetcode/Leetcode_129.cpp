// 求根到叶子节点数字之和
class Solution {
public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        helper(root, 0);
        return res;
    }

    void helper(TreeNode* root, int sum) {
        if(root == nullptr) return;
        if(!root->left && !root->right) res += sum * 10 + root->val;
        helper(root->left, sum * 10 + root->val);
        helper(root->right, sum * 10 + root->val);
    }
};