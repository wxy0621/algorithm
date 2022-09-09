// 填充每个节点的下一个右侧节点指针 II
// BFS
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* pre;
            Node* nex;
            pre = q.front();
            q.pop();
            if (pre->left) q.push(pre->left);
            if (pre->right) q.push(pre->right);
            if (n > 1) {
                for (int i = 0; i < n - 2; ++i) {
                    nex = q.front();
                    q.pop();
                    pre->next = nex;
                    pre = nex;
                    if (nex->left) q.push(nex->left);
                    if (nex->right) q.push(nex->right);
                }
                nex = q.front();
                q.pop();
                pre->next = nex;
                nex->next = nullptr;
                if (nex->left) q.push(nex->left);
                if (nex->right) q.push(nex->right);
            } else {
                pre->next = nullptr;
            }
        }
        return root;
    }
};