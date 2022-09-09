// 填充每个节点的下一个右侧节点指针
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* pre = q.front();
                q.pop();
                if (i != n-1) {
                    Node* cur = q.front();
                    pre->next = cur;
                } else {
                    pre->next = nullptr;
                }
                if (pre->left) q.push(pre->left);
                if (pre->right) q.push(pre->right); 
            }
        }
        return root;
    }
};