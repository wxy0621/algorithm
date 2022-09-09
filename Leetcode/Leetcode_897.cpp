// 递增顺序查找树
// 中序遍历
class Solution {
public:
    vector<int> v;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* res = new TreeNode(0), *cur = res;
        inorder(root);
        for(int& a: v) {
            cur->right = new TreeNode(a);
            cur = cur->right;
        }
        return res->right;
    }
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        v.emplace_back(root->val);
        inorder(root->right);
    }
};