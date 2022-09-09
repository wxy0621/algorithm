// 从上到下打印二叉树 II
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> layer;
            for(int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                layer.emplace_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.emplace_back(layer);
        }
        return res;
    }
};