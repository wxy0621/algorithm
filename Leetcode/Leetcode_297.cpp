// 二叉树的序列化与反序列化
// 有点复杂，几种方法融合
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp) {
                res += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            } else res += "null,";
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data);
        if(vals[0] == "null") return nullptr;
        queue<TreeNode*> q;
        auto p = new TreeNode(stoi(vals[0]));
        q.push(p);
        TreeNode* res = p;
        for(int i = 1; i < vals.size();) {
            if(vals[i] != "null") {
                auto p = new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->left = p;
            }
            ++i;
            if(vals[i] != "null") {
                auto p = new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->right = p;
            }
            ++i;
            q.pop();
        }
        return res;
    }
    vector<string> split(string& data) {
        int start = 0;
        vector<string> res;
        while(true) {
            auto end = data.find(',', start);
            if(end == string::npos) break;
            res.emplace_back(data.substr(start, end - start));
            start = end + 1;
        }
        return move(res);
    }

};