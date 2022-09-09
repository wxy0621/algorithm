// 二叉搜索树中的搜索
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val > val) {
            root = searchBST(root->left, val);
            return root;
        }
        if(root->val < val) {
            root = searchBST(root->right, val);
            return root;
        }
        return root;
    }
};