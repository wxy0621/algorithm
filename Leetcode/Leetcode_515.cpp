// 在每个树行中找最大值
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return { };
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int max_floor = INT_MIN;
            for(int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                max_floor = max(max_floor, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.emplace_back(max_floor);
        }
        return res;
    }
};