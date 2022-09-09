// 特定深度节点链表
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(!tree) return { };
        vector<ListNode*> res;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty()) {
            int n = q.size();
            ListNode* floor = new ListNode(0);
            ListNode* cur = floor;
            for(int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                ListNode* t = new ListNode(temp->val);
                cur->next = t;
                cur = cur->next;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.emplace_back(floor->next);
        }
        return res;
    }
};