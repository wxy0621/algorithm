// 验证二叉搜索树
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }
    bool helper(TreeNode* root, long long upper, long long lower) {
        if(root == nullptr)
            return true;
        if(root->val >= upper || root->val <= lower)
            return false;
        return helper(root->left, root->val, lower) && helper(root->right, upper, root->val);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long long inorder = (long long)INT_MIN - 1;

        while(!s.empty() || root != nullptr) {
            while(root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(inorder >= root->val) return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};