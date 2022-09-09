// 把二叉搜索树转换为累加树
// 递归
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->right);
        root->val += sum;
        sum = root->val;
        dfs(root->left);
    }
};

// 迭代
class Solution2 {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* p = root;
        stack<TreeNode*> s;
        while(!s.empty() || p) {
            while(p) {
                s.push(p);
                p = p->right;
            }
            p = s.top();
            s.pop();
            sum += p->val;
            p->val = sum;
            p = p->left;
        }
        return root;
    }
};