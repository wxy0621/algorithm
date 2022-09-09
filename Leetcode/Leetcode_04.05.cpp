// 合法二叉搜索树
class Solution {
public:
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        helper(root);
        for(int i = 1; i < res.size(); ++i) {
            if(res[i] <= res[i - 1]) return false;
        }
        return true;
    }
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root->left);
        res.emplace_back(root->val);
        helper(root->right);
    }
};