//  二叉树的中序遍历
// 递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        dfs(root->left, res);
        res.emplace_back(root->val);
        dfs(root->right, res);
    }
};

// 栈
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.emplace_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

// 莫里斯遍历
// 不断将左子树加到 cur 节点的父节点位置，cur 节点变为左子树的最右节点的右节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                res.emplace_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right != nullptr) {
                    pre = pre->right;
                }
                pre->right = cur;
                TreeNode* temp = cur;
                cur = cur->left;
                temp->left = nullptr;
            }
        }
        return res;
    }
};