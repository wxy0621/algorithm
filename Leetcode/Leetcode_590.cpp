// 叉树的后序遍历
// 递归
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if(root == nullptr) return {};
        dfs(root);
        return res;
    }
    void dfs(Node* root) {
        if(root == nullptr) return;
        for(int i = 0; i < root->children.size(); ++i) {
            dfs(root->children[i]);
        }
        res.emplace_back(root->val);
    }
};

// 迭代
class Solution2 {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            res.emplace_back(temp->val);
            for(int i = 0; i < temp->children.size(); ++i) {
                s.push(temp->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

