// 二叉树的层平均值
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return {};
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            double average = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                average += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            average /= n;
            res.emplace_back(average);
        }
        return res;
    }
};