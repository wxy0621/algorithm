// 二叉树的层次遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector< vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();
                temp.emplace_back(t->val);
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
            res.emplace_back(temp);
        }
        return res;
    }
};