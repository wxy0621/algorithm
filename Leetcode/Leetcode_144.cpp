// 二叉树的前序遍历
// 递归
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        helper(root);
        return res;
    }
    void helper(TreeNode* root) {
        if(!root) return;
        res.emplace_back(root->val);
        helper(root->left);
        helper(root->right);
    }
};

// 迭代
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            res.emplace_back(temp->val);
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
        return res;
    }
};