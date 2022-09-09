// 叶子相似的树
// dfs
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 != nullptr) return false;
        if(root1 != nullptr && root2 == nullptr) return false;
        vector<int> r1;
        vector<int> r2;
        dfs(root1, r1);
        dfs(root2, r2);
        int n1 = r1.size(), n2 = r2.size();
        if(n1 != n2) return false;
        for(int i = 0; i < n1; ++i) {
            if(r1[i] != r2[i]) return false;
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int>& r) {
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr) r.emplace_back(root->val);
        dfs(root->left, r);
        dfs(root->right, r);
    }
};