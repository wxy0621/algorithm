// N叉树的前序遍历
// 递归
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root) return {};
        helper(root);
        return res;
    }
    void helper(Node* root) {
        if(!root) return;
        res.emplace_back(root->val);
        for(int i = 0; i < root->children.size(); ++i) {
            helper(root->children[i]);
        }
    }
};

// 迭代
class Solution2 {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            int n = temp->children.size();
            res.emplace_back(temp->val);
            for(int i = n - 1; i >= 0; --i) s.push(temp->children[i]);
        }
        return res;
    }
};