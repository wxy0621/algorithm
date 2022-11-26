// 叉树的右侧视图
// bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            TreeNode* temp;
            for (int i = 0; i < n - 1; ++i) {
                temp = que.front();
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
                que.pop();
            }
            temp = que.front();
            res.emplace_back(temp->val);
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
            que.pop();
        }
        return res;
    }
};