// 往完全二叉树添加节点
// 队列
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root = root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            if (!(temp->left && temp->right)) candidate.push(temp);
        }
    }
    
    int insert(int v) {
        TreeNode* newNode = new TreeNode(v);
        TreeNode* res = candidate.front();
        if (!res->left) {
            res->left = newNode;
        } else {
            res->right = newNode;
            candidate.pop();
        }
        candidate.push(newNode);
        return res->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
private:
    TreeNode* _root;
    queue<TreeNode*> candidate;
};