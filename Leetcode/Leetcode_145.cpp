// 二叉树的后序遍历
// 递归
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        dfs(root->right);
        res.emplace_back(root->val);
    }
};

// 迭代
// 栈，再逆序
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            res.emplace_back(temp->val);
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};