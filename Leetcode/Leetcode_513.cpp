// 找树左下角的值
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return -1;
        int res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            res = q.front()->val;
            for (int i = 0; i < n; ++i) {
                TreeNode* layer = q.front();
                q.pop();
                if (layer->left) q.push(layer->left);
                if (layer->right) q.push(layer->right);
            }
        }
        return res;
    }
};