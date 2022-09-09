// N叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> t;
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                Node* temp = q.front();
                q.pop();
                t.emplace_back(temp->val);
                for(int j = 0; j < temp->children.size(); ++j) {
                    q.push(temp->children[j]);
                }
            }
            res.emplace_back(t);
        }
        return res;
    }
};