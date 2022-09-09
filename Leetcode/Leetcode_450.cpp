// 删除二叉搜索树中的节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // 当 key = root->val
        if(!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 找到 root->right 的最左边节点
        TreeNode* temp = root->right;
        while(temp->left) temp = temp->left;
        swap(temp->val, root->val);
        root->right = deleteNode(root->right, key);
        return root;
    }
};