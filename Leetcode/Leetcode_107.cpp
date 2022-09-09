// 二叉树的层次遍历II

// 栈
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        stack< vector<int> > s;
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
            s.emplace(temp);
        }
        while(!s.empty()) {
            res.emplace_back(s.top());
            s.pop();
        }
        return res;
    }
};

// reverse
class Solution2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(res.begin(), res.end());
        return res;
    }
};