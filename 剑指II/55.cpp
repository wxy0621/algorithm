// 二叉搜索树迭代器
// dfs
class BSTIterator {
public:
    BSTIterator(TreeNode* root): cur(root) {}
    
    int next() {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }
    
    bool hasNext() {
        return cur || !stk.empty();
    }
private:
    TreeNode* cur;
    stack<TreeNode*> stk;
};