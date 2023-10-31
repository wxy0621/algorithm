// 出现次数最多的子树元素和
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        maxCount = 0;
        vector<int> res;
        dfs(root);
        for (auto& t: m) {
            if (t.second == maxCount) {
                res.emplace_back(t.first);
            }
        }
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        maxCount = max(maxCount, ++m[sum]);
        return sum;

    }
private:
    unordered_map<int, int> m;
    int maxCount;
};