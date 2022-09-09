// 从上到下打印二叉树 III
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector< vector<int> > res;
        q.push(root);
        bool flag = true;
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp.emplace_back(t->val);
            }
            if(flag == false) {
                reverse(temp.begin(), temp.end());
            }
            flag = flag ? false : true;
            res.emplace_back(temp);
        }
        return res;
    }
};