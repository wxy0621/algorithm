// 二叉搜索树迭代器
// 中序遍历
class BSTIterator {
protected:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        int res = temp->val;
        temp = temp->right;
        while(temp) {
            s.push(temp);
            temp = temp->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};