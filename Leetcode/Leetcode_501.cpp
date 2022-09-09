// 二叉搜索树中的众数
// 中序遍历
class Solution {
public:
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(!root) return { };
        TreeNode* pre = nullptr;
        int count = 1, max_count = 0;
        dfs(root, count, pre, max_count);
        return res;
    }
    void dfs(TreeNode* root, int& count, TreeNode*& pre, int& max_count) {
        if(!root) return;
        dfs(root->left, count, pre, max_count);
        if(pre) count = (pre->val == root->val) ? count + 1 : 1; 
        if(max_count == count) res.emplace_back(root->val);
        else if(max_count < count) {
            res.clear();
            res.emplace_back(root->val);
            max_count = count;
        }
        pre = root;
        dfs(root->right, count, pre, max_count);
    }
};