// 路径总和II
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return {};
        vector< vector<int> > res;
        vector<int> temp;
        int temp_sum = 0;
        dfs(root, res, temp, sum, temp_sum);
        return res;
    }

    void dfs(TreeNode* root, vector< vector<int> >& res, vector<int>& temp, int sum, int& temp_sum) {
        if(root == nullptr) return;
        temp_sum += root->val;
        temp.emplace_back(root->val);
        bool leaf = (root->left == nullptr) && (root->right == nullptr);
        if(temp_sum == sum && leaf) {
            res.emplace_back(temp);
        }
        dfs(root->left, res, temp, sum, temp_sum);
        dfs(root->right, res, temp, sum, temp_sum);
        temp.pop_back();
        temp_sum -= root->val;
    }
};