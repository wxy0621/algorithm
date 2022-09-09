// 翻转二叉树
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        
        root->left = left;
        root->right = right;

        return root;
    }
};

// 速度快了，不知道原因
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;
        // swap(root->left, root->right);

        return root;
    }
};

// 队列，速度慢，空间大
class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            swap(temp->left, temp->right);
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
        return root;
    }
};

// 栈，空间大
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            swap(temp->left, temp->right);
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
        }
        return root;
    }
};