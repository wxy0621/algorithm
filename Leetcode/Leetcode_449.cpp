// 序列化和反序列化二叉搜索树
class Codec {
public:
    // Encodes a tree to a single string.
    void serializeDfs(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        serializeDfs(root->left, res);
        serializeDfs(root->right, res);
    }
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res;
        serializeDfs(root, res);
        return res;
    }
    TreeNode* helper(queue<string>& q) {
        if (q.empty()) return nullptr;
        if (q.front() == "#") {
            q.pop();
            return nullptr;
        }
        int _val = stoi(q.front());
        q.pop();
        TreeNode* res = new TreeNode(_val);
        res->left = helper(q);
        res->right = helper(q);
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        queue<string> q;
        string lastStr = "";
        for (int i = 0; i < n; ++i) {
            if (data[i] == ',') {
                q.push(lastStr);
                lastStr = "";
            } else {
                lastStr += data[i];
            }
        }
        TreeNode* res = helper(q);
        return res;
    }
};