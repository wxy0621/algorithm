// 序列化二叉树
// 队列
class Codec {
public:
  	void serializeDfs(TreeNode* root, string& res) {
      	if (!root) {
          	res += "nullptr,";
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
  
  	TreeNode* helper(queue<string>& vec) {
      	if (vec.empty()) return nullptr;
      	if (vec.front() == "nullptr") {
          	vec.pop();
          	return nullptr;
        }
      	int _val = stoi(vec.front());
      	TreeNode* res = new TreeNode(_val);
      	vec.pop();
        res->left = helper(vec);
      	res->right = helper(vec);
        return res;
    }
  
    TreeNode* deserialize(string data) {
      	int n = data.size();
        if (n == 0) return nullptr;
      	queue<string> vec;
      	string lastStr = "";
      	for (int i = 0; i < n; ++i) {
          	if (data[i] == ',') {
              	vec.push(lastStr);
                lastStr = "";
            } else {
              	lastStr += data[i];
            }
        }
      	// if (lastStr.size() != 0) vec.push(lastStr);
      	TreeNode* res;
      	res = helper(vec);
      	return res;
    }
};