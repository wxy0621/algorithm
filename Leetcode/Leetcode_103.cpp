// 二叉树的锯齿形层次遍历
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector< vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()) {
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                temp.emplace_back(t->val);
                q.pop();
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
            if(flag % 2 == 1) reverse(temp.begin(), temp.end());
            res.emplace_back(temp);
            ++flag;
        }
        return res;
    }
};